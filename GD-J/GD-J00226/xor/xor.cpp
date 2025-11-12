#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int xr[500005];
int xr_las[2000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
		xr[i]=(xr[i-1]^a[i]);
	int ans=0,ganggang=0;
	memset(xr_las,-1,sizeof xr_las);
	xr_las[0]=0;
	for(int i=1;i<=n;++i){
		int zhao=xr[i]^k;
		if(xr_las[zhao]!=-1){
			if(xr_las[zhao]>=ganggang){
				++ans;
				ganggang=i;
			}
		}
		xr_las[xr[i]]=i;
	}
	cout<<ans;
	return 0;
}
