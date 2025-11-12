#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a,s=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		s^=a;
		if(s==k){
			ans++;
			s=0;
		}
	}
	cout<<ans;
	return 0;
}
