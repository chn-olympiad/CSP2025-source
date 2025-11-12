#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,k,u[N],v[N],w[N],bol[N]={};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int c,a[N];
	for(int i=0;i<m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=0;i<k;i++){
		cin>>c;
		for(int i=0;i<n;i++)cin>>a[i];
	} 
	int minn,mini,ans=0;
	for(int i=0;i<n-1;i++){
		minn=99999999,mini=0;
		for(int j=0;j<m;i++){
			if(minn>w[j]&&bol[j]==0){
				minn=w[j];
				mini=j;
			}
			ans+=minn;
			bol[mini]=1;
		}
	}
	cout<<ans;
	return 0;
} 
