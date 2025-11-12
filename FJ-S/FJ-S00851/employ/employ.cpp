#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read() {
	ll e=1,v=0;
	char s=getchar();
	while(s<'0'||s>'9') {
		if(s=='-') {
			e=-1;
			s=getchar();
			break;
		} else s=getchar();
	}
	while(s>='0'&&s<='9') {
		v=(v<<3)+(v<<1)+s-'0';
		s=getchar();
	}
	return e*v;
}
ll t,n,m,c[501],nm[501],mod=998244353,d,sum,wu[501],q[501],fu[501],ck,ss;
string sb;
inline void dfs(ll day,ll r) {
	if(day==n+1&&r>=m) {
		sum=(sum+1)%mod;
		return ;
	}
	for(int i=1; i<=n; i++) {
		//cout<<i<<" "<<day<<" "<<wu[day-1]<<" "<<fu[day-1]<<" "<<c[i]<<endl;
		if(sb[day-1]=='0')dfs(day+1,r);
		else
		if(nm[i]==0&&c[i]>=max(wu[day-1],fu[day-1]-r)&&sb[day-1]=='1'){
			nm[i]=1;
			dfs(day+1,r+1);
			nm[i]=0;
		}
		//cout<<i<<" "<<day<<" "<<wu[day]<<" "<<fu[day]<<" "<<c[i]<<endl;
	}
	return ;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	cin>>sb;
	for(int i=1; i<=n; i++) {
		if(sb[i-1]=='0') {
			for(int j=i; j<=n; j++)wu[j]++;
		}
	}
	for(int i=1; i<=n; i++) {

		c[i]=read();
		q[i]=c[i];
	}
	sort(q+1,q+n+1);
	for(int i=1; i<=n+1; i++) {
		if(q[i]!=ck) {
			fu[q[i-1]]=ss;
			ss++;
			ck=q[i];
		} else {
			ss++;
		}
	}
	dfs(1,0);
	cout<<(sum%mod)/n;
	return 0;
}
//3 2 101 1 1 2
