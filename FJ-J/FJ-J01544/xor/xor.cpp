#include<bits/stdc++.h>
using namespace std;
const int N=5*5e5+5;
long long n,k,ans;
long long s[N],a[N];
int main (){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		cout<<n/2;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=a[i]^s[i-1];
		if(s[i]==k){
			ans++;
			s[i]=0;
		}
		for(int j=1;j<i;j++){
			if((s[i]^s[j])==k){
				ans++;
				s[i]=0;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

