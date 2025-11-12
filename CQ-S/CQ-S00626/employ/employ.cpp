#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=998244353;
int n,m,ans=0;
int p[N],a[N];
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=i;
	}
	do{
		int now=0,num=0;
		for(int i=1;i<=n;i++){
			if(a[p[i]]<=now){
				now++;
				continue;
			}
			if(s[i]=='0')now++;
			else num++;
		}
		if(num>=m)ans=(ans+1)%mod;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
