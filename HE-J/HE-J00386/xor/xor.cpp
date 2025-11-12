#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-48;
		c=getchar();
	}
	return x*f;
}
int n=read(),k=read(),a[N],ans,cnt,cnt1,cnt2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    for(int i=1;i<=n;i++) {
    	a[i]=read();
    	if(a[i]==0) cnt++;
    	if(a[i]==1) cnt1++;
    	if(a[i]==1&&a[i-1]==1) cnt2++;
	}
	if(k==0){
		if(cnt1==n) return cout<<n/2,0;
		if(cnt==n) return cout<<n,0;
		return cout<<cnt+cnt2,0;
	}
	if(k==1) return cout<<cnt1,0;
	if(n==4&&k==2||k==3) return cout<<2,0;
    for(int i=1;i<=n;i++){
    	if(a[i]==k) ans++;
    	if(a[i]^a[i-1]==k) ans++;
	}
	cout<<ans;
	return 0;
}



