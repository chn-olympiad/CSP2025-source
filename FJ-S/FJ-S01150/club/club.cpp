#include<bits/stdc++.h>
using namespace std;
void dd(int &ss){
	ss=0;
	char ch=getchar();int ff=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while('0'<=ch&&ch<='9')ss=ss*10+ch-'0',ch=getchar();
	ss*=ff;
}
const int N=1e6+5;
priority_queue<int>dui[4];
int T,n,tong[4];
int a[N][4],maxx[N],cmax[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	dd(T);
	while(T--){
		dd(n);
		for(int i=1;i<=3;++i)
		while(dui[i].size())dui[i].pop();
		tong[3]=tong[1]=tong[2]=0;
		for(int i=1;i<=n;++i){
			dd(a[i][1]),dd(a[i][2]),dd(a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])maxx[i]=1,cmax[i]=(a[i][2]>a[i][3]?2:3);
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])maxx[i]=2,cmax[i]=(a[i][1]>a[i][3]?1:3);
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])maxx[i]=3,cmax[i]=(a[i][1]>a[i][2]?1:2);
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			dui[maxx[i]].push(a[i][cmax[i]]-a[i][maxx[i]]);
			ans+=a[i][maxx[i]];
			if(tong[maxx[i]]==n/2){
				ans+=dui[maxx[i]].top(),dui[maxx[i]].pop();
			}else{
				++tong[maxx[i]];
			}
		}
		cout<<ans<<'\n';
	}
}
