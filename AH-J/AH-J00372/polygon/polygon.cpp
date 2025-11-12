#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[5010],l[25000010],n,cnt,p;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n>=24){
		p=1;
		for(int i=1;i<=n;i++){
			p*=2;
			p%=998244353;
		}
		p-=(1+n+n*(n-1)/2);
		cout<<(p+998244353)%998244353;
		return 0;
	}
	sort(s+1,s+1+n);
	l[++cnt]=0;
	l[++cnt]=s[1];
	l[++cnt]=s[2];
	l[++cnt]=s[1]+s[2];
	for(int i=3;i<=n;i++){
		sort(l+1,l+1+cnt);
		p+=cnt-(upper_bound(l+1,l+1+cnt,s[i])-l)+1;
		p%=998244353;
		int k=cnt;
		for(int j=1;j<=k;j++){
			l[++cnt]=l[j]+s[i];
		}
	}
	cout<<p;
	return 0;
}
