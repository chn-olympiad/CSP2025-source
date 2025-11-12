#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int n,m,c[5000],olol,lolo;
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	bool flag=true;
	for(int i=0; i<n; i++) {
		if(!(s[i]-'0'))flag=false;
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
		if(c[i])olol++;
		else lolo++;
	}
	if(olol<m) {
		cout<<0;
		return 0;
	} else if (m==n) {
		cin>>s;
		for(int i=0; i<n; i++) {
			if(!(s[i]-'0')) {
				printf("%d",0);
				return 0;
			}
		}
	} else if(m==1) {
		cout<<olol;
		return 0;
	} else if(flag) {
		long long sum=1;
		for(int i=n; i>=n-m+1; i--) {
			sum*=i;
			sum%=N;
		}
		cout<<sum%N;
		return 0;
	}
	return 0;
}

