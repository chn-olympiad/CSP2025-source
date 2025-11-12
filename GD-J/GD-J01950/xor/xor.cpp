#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+2e5;
ll n,k,a[N],s[N]={0},ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		int c=s[i-1]^a[i];
		s[i]=c;
	}
	for (int i=0;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			int z=s[i]^s[j];
			if (z==k){
				ans++;
//				cout<<i<<" "<<j<<" "<<s[i]<<" "<<s[j]<<" "<<a[i]<<" "<<a[j]<<" "<<z<<endl;
				i=j-1;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
