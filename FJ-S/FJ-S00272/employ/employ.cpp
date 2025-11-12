#include<bits/stdc++.h>
using namespace std;
int n,m,a[502],b[502],c[502],e,f,l,d[502];
long long ans,dp[502];
string s;

int df(int x) {
	int y=d[x];
	int o=y+1;
	for(int i=y+1; i<=o; i++) {
		o+=c[i];
	}
	return o;
}
void sss(int x,int y) {
	dp[0]=1;
	f=l;
	for(int i=1; i<=n; i++) {
		if(b[i]!=49) {
			f--;
		}
		if(i>=x,i<=y) {
			int sum=max(max(f,i-1),d[n-i]-f);
			int sxs=min(d[i-1],n);
			dp[i]=n-sum;
		} else {
			dp[i]=n-i+1;
		}
	}
	return ;
}
void sxs() {
	int L=1,R=1;
	while(R<=n) {
		if(L<R-m) {
			l++;
		}
		if(L==R-m) {
			sss(L,R);
			int mm=1;
			for(int i=1; i<=n; i++) {
				mm=(mm*dp[i])%998277353;
			}
			ans+=mm;
			R++;
		}
		if(L>R-m) {
			R=L+m;
		}
	}

	return ;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=0; i<n; i++) {
		b[i+1]=s[i];
		if(b[i+1]==48) {
			l++;
			d[i+1]=min(df(i),n);
		} else {
			d[i+1]=d[i];
		}
	}
	if(n-l<m) {
		cout<<0;
	} else if(l==0) {
		ans=1;
		for(int i=1; i<=n; i++) {
			ans=(ans*i)%998277353;
		}
		cout<<ans;
	} else if(n-d[n]>=m) {
		ans=1;
		for(int i=1; i<=n; i++) {
			ans=(ans*i)%998277353;
		}
		cout<<ans;
	} else if(d[m]==0) {
		ans=1;
		for(int i=1; i<=n; i++) {
			ans=(ans*i)%998277353;
		}
		cout<<ans;
	} else {
		ans=1;
		sxs();
		cout<<ans;
	}

	return 0;
}
