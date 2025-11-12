#include<bits/stdc++.h>
#define int long long int
using namespace std;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10005],cnt=0;
	bool p[10005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=pow(2,n);i++){
		int k=1;
		while(p[k]==1){
			p[k]=0;
			k++;
		}
		p[k]=1;
		int sum=0,mmax=0;
		for(int j=1;j<=n;j++){
			
			if(p[j]==1){
				sum+=a[j];
				mmax=max(mmax,a[j]);
			}
		}
		if(mmax*2<sum) cnt++;
	}
	cout<<cnt%998%244%353<<endl;
	return 0;
}
