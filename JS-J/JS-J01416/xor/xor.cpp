#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k;
long long a[N],s[N],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	f[0]=0;
	for (int i=1;i<=n;i++){
		long long flag=s[i]^k;
		long long c=0;
		for (int j=i;j>=0;j--){
			if (s[j]==flag){
				c=j;
				break;
			}
		}
		f[i]=max(f[i-1],f[c]+1);
	}
	cout<<f[n];
	return 0;
}
