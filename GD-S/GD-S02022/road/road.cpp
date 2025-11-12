#include<bits/stdc++.h>
using namespace std;
//最小生成树？
int n,m,k;
int f[100005];
int find(int a){
	if(f[a]==a){
		return a;
	}else{
		return f[a]=find(f[a]);
		
	}
}
struct side{
	int a,b,size;
	//联通了哪里,花费 
}r[100000005];
bool cmp(side a,side b){
	return a.size<b.size;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long ans=0;
	long long cnt=1;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>r[cnt].a>>r[cnt].b>>r[cnt].size;
		cnt++;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int k;
			cin>>k;
			if(i==j){
				continue;
			}else{
				r[cnt].a=i;
				r[cnt].b=j;
				r[cnt].size=k;
				cnt++;
			}
		}
	}
	sort(r+1,r+cnt,cmp);
	long long sss=0;
	for(int i=1;i<=cnt-1;i++){
		if(find(r[i].a)==find(r[i].b)){
			continue ;
		}else{
			
			f[find(r[i].a)]=find(r[i].b);
			ans=ans+r[i].size;
			sss++;
		}
		if(sss==n-1){
			break;
		}
	}
	
	cout<<ans;

}
