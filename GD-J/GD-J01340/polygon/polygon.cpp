#include<bits/stdc++.h>
using namespace std;
const int mod=998244353; 
long long n;
long long a[5005],s[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		int t=a[i]*2;
		if(s[i]<=t) continue;
		ans++;
		if(i>3){
			for(int j=1;j<=i;j++){
				if(s[i]-a[j]>t) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
