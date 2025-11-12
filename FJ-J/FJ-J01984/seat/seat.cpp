#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;
	char ch=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=read(),m=read();
	int a[100];
	int s=0;
	for(int i=0;i<m*n;i++){
		a[i]=read();
		if(a[i]>=a[0])s++;
	}
	int c=(s-1)/n+1,r=(s-1)%n+1;
	if(c%2==1)cout<<c<<" "<<r;
	else cout<<c<<" "<<n-r+1;
	return 0;
}
