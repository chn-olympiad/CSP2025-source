#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
void d(int c,int l,long long t){
	for(int i=l+1;i<=n;i++){
		//cout<<"now="<<i<<endl;
		//cout<<c<<" "<<l<<" "<<t<<endl;
		if(t>a[i]&&c>=3){
			ans++;
			//cout<<"ans="<<ans<<endl;
		}
		d(c+1,i,t+a[i]);
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int j=2;j<=n-3;j++)
		for(int i=j-1;i<=n;i++) d(j,i,a[i]);
	cout<<ans%998244353;
	return 0;
}
