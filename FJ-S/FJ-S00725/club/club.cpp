#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,ans,siz[3];
array<int,3> a[N];
set<array<int,2>> cost[3][3];
int read(){
	int res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9')
		res=res*10+ch-'0',ch=getchar();
	return res;
}
void insert(int id,int cl){
	ans+=a[id][cl],siz[cl]++;
	for(int i=0;i<3;i++) if(i!=cl)
		cost[cl][i].insert({a[id][i]-a[id][cl],id});
}
void erase(int id,int cl){
	ans-=a[id][cl],siz[cl]--;
	for(int i=0;i<3;i++) if(i!=cl)
		cost[cl][i].erase({a[id][i]-a[id][cl],id});
}
array<int,4> query(){
	array<int,4> res={0,0,0,0};
	for(int id1=0;id1<3;id1++) if(siz[id1]){
		for(int id2=0;id2<3;id2++) if(id1!=id2){
			array<int,2> arr=(*cost[id1][id2].rbegin());
			if(siz[id2]<n/2)
				res=max(res,{arr[0],arr[1],id1,id2});
		}
	}
	return res;
}
array<int,6> Query(){
	array<int,6> res={0,0,0,0,0,0}; 
	for(int id1=0;id1<3;id1++) if(siz[id1])
		for(int id2=0;id2<3;id2++) if(id1!=id2&&siz[id2]==n/2){
			array<int,2> arr=(*cost[id1][id2].rbegin());
			if(siz[id1]!=n/2){
				for(int id3=0;id3<3;id3++) if(id2!=id3){
					array<int,2> Arr=(*cost[id2][id3].rbegin());
					res=max(res,{arr[0]+Arr[0],id1,id2,id3,arr[1],Arr[1]});
				}
			}else{
				int id3=id1;
				array<int,2> Arr=(*cost[id2][id3].rbegin());
				res=max(res,{arr[0]+Arr[0],id1,id2,id3,arr[1],Arr[1]});
			}
		}
	return res;
}
void work(){
	ans=0;
	for(int i=0;i<3;i++){
		siz[i]=0;
		for(int j=0;j<3;j++)
			cost[i][j].clear();
	}
	n=read();
	for(int i=1;i<=n;i++)
		a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
	for(int i=1;i<=n/2;i++) insert(i,0);
	for(int i=n/2+1;i<=n;i++) insert(i,1);
	while(true){
		array<int,4> res=query();
		if(res[0]<=0) break;
		erase(res[1],res[2]),insert(res[1],res[3]);
	}
	while(true){
		array<int,6> res=Query();
		if(res[0]<=0) break;
		erase(res[4],res[1]),insert(res[4],res[2]);
		erase(res[5],res[2]),insert(res[5],res[3]);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	for(int T=read();T;T--) work();
}
