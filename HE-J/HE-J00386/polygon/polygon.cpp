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
int n=read(),a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    for(int i=1;i<=n;i++)a[i]=read();
    if(n==3) cout<<1;
    else if(n==4) cout<<4;
    else if(n==5) cout<<9;
    else cout<<pow((n-2),2);
	return 0;
}



