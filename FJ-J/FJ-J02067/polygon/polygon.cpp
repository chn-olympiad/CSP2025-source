#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,k,a[5005];
	long long ans=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	for(int i=n;i>=3;i--){
	for(int k=1;k<=i-2;k++){
		for(int j=k;j<=i-1;j++){
			s+=a[j];
			if(s>a[i]){
				int x=j,y=i-j-1;
				ans+=1+x*y+(1+y)*y/2;
				cout<<ans<<" "<<x<<" "<<endl;
				break;
			}
		}
		s=0;
	}
		
	}
	for(int i=n;i>=3;i--){
		for(int j=i-1;j>=k;j--){
			s+=a[j];
			if(s>a[i]&&i-j>=2){
				ans+=1;
				cout<<ans<<endl;
				break;
			}
		}
		s=0;
	}
	cout<<ans%998244353;
}
