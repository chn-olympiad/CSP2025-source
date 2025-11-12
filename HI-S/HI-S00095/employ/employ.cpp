#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m;
char s[N];
long long c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);
	if(m==1){
		long long ans;
		int k=0;
		while(k<=n){
			while(s[k]=='0'&&k<=n)k++;
			if(k>=n)break;
			int nk=n-k;
			for(int i=1;i<=n;i++)
				if(c[i]>nk){
					long long sum=1;
					for(long long i=n-1;i>=1;i--){
						sum=(sum*i)%998244353;
						sum%=998244353;
					}
					ans+=sum;
					ans%=998244353;
				}
			k++;
		}
		cout<<ans;
	}
	else if(n==m){
		for(int i=0;i<n;i++)if(s[i]=='0'){
			cout<<0;return 0;
		}
	}
	return 0;
}
