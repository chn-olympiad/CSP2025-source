//GZ-S00216 贵阳市花溪区同为京学附属实验学校 李嘉成 
#include <bits/stdc++.h>
using namespace std;
struct l{
	long long v,u,w;
}a[1000005];
long long b[15],c[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	bool x=0;
	cin>>n>>m>>k;	
	for(int i=1;i<=m;i++) c[i]=i;
	for(int i=1;i<=m;i++){
		bool f=1;
		cin>>a[i].v>>a[i].u>>a[i].w;
		if(c[a[i].v]!=0&&c[a[i].u]!=0){
			c[a[i].v]=0;
			c[a[i].u]=0;
			ans+=a[i].w;
		}
		else if(a[i].v!=0){
			c[a[i].v]=0;
			ans+=a[i].w;
		}
		else if(a[i].u!=0){
			c[a[i].u]=0;
			ans+=a[i].w;	
		}
		for(int i=1;i<=1000005;i++){
			if(c[i]!=0){
				f=0;
				break;
			}
		}
		if(f==1){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
