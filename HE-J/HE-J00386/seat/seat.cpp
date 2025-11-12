#include<bits/stdc++.h>
using namespace std;
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
int n=read(),m=read(),a[200];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=1; i<=n*m; i++)a[i]=read();
	int x=a[1],r=1,c;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++){
		if(i%n==0)c=i/n;
		else c=i/n+1;
		if(a[i]==x) return cout<<c<<' '<<r,0;
		if(c%2==1&&r!=n) r++;
		else if(c%2==0&&r!=1) r--;
	}
	return 0;
}



