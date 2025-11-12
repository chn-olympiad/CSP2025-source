#include<bits/stdc++.h>
#define mn 5001
#define mod 998244353
using namespace std;
int n,a[mn],b[mn],m,i,step=3,ans,fuck;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		cout<<a[i]<<' ';
		b[i]=a[i];
	}
	cout<<endl;
	for(i=1;i<=n;i++){
		a[i]+=a[i-1];
		b[i]=max(b[i],b[i-1]);
	}
	for(i=1;i<=n;i++){
		cout<<a[i]<<' '; 
	}
	cout<<endl;
	while(step<=n){
		fuck=0;
		for(i=step;i<=n;i++){
			if(a[i]-a[fuck]>2*b[i]){
				cout<<step<<' '<<a[i]-a[fuck]<<endl;
				ans++;
			}
			fuck++;
		}
		step++;
	}
	cout<<ans%mod;
	return 0;
}
