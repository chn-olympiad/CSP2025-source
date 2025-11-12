#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
inline int read() {
	int x=0;
	short f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
int n,k,a[N];
long long s[N],ans=0;
bool f=0,f2=0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for(int i=1; i<=n; i++) {
		a[i]=read();
		if(a[i]!=1)
			f=1;
	}
	if(!f&&k==0) {
		if(n%4!=0)
			cout<<0;
		else
			cout<<n/2;
		return 0;
	}
	int t;
	long long sum;
	f2=0;
    for(int i=1; i<=n; i++) {
		if(sum==0&&(f2==1||i==1))
	      sum=a[i];
	    f2=0;
		if(sum==k)
			ans++,sum=0,f2=1;
        if(sum!=0||f2==0)
	    	sum^=a[i];
	}
	cout<<ans;
	return 0;
}
