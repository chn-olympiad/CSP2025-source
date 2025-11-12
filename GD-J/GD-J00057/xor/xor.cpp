#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],f[3200005],n,k,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	f[0]=1;
	long long t=1;
	for(int i=1;i<=n;i++){
		if(f[s[i]^k]==t){
			ans++,t++;
		}
		f[s[i]]=t;
	}
	cout<<ans;
	return 0;
}
