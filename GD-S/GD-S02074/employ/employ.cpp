#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read() {
	ll op=1,x=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {
			op=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*op;
}
ll n,m;
ll b[500];
string s;
bool chec() {
	ll op=0,jkl=0;
	for(int i=1; i<=n; i++) {
	//	cout<<b[i]<<" " ;
		if(s[i-1]=='0'||op>=b[i]) {
			op++;
		} else {
			jkl++;
	//		cout<<"ryt"<<i<<"fhdfh";
		}
	}
//	cout<<endl;
	if(jkl>=m) {
		return 1;
	} else {
		return 0;
	}
}
ll ff(ll x) {
	ll op=1;
	for(int i=2; i<=x; i++) {
		op*=i;
		op%=998244353;
	}
	return op;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	cin>>s;
	for(int i=1; i<=n; i++) {
		b[i]=read();
	}
	sort(b+1,b+1+n);
	if(!chec()) {
		cout<<0;
		return 0;
	} else {
		ll kl=1;
		ll op=b[1],po=1;
		ll jkl=0;
		ll a[5000],c[5000],d[5000];
		c[1]=jkl+1;
		for(int i=2; i<=n; i++) {
			if(b[i]==op) {
				po++;
			} else {
				jkl++;
				a[jkl]=po;
				d[jkl]=b[i-1];
				kl*=ff(po);
				kl%=998244353;
				op=b[i];
				po=1;
			}
			c[i]=jkl+1;
		}
		jkl++;
		a[jkl]=po;
		d[jkl]=b[n];
		kl*=ff(po);
		kl%=998244353;
	//	cout<<"op";
//		for(int i=1; i<=n; i++) {
//			
//			cout<<c[i]<<" ";
//		}
//		cout<<endl;
//		cout<<"jkl";
//		for(int i=1; i<=jkl; i++) {
//			
//			cout<<a[i]<<" "<<d[i]<<"|";
//		}
//		cout<<endl;
		for(int i=1; i<=n; i++) {
			for(int j=c[i]-1; j>=1; j--) {
				swap(b[i],d[j]);
				if(chec()){
					swap(b[i],d[j]);
					kl*=ff(a[j]);
					kl%=998244353;
				}else{
					swap(b[i],d[j]);
					break;
				}
			}
		}
		cout<<kl;
	}
	return 0;
}
