#include<bits/stdc++.h>
using namespace std;
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
bool cmp(int a,int b) {
	return a>b;
}
int a[105],t,h=1,l=1;
int n,m;
bool f=0;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	for(int i=1; i<=n*m; i++)
		a[i]=read();
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++) { 
		f=0;
		if(a[i]==t) {
			cout<<l<<' '<<h;
			break;
		}
		if((h==1&&l!=1&&l%2==0)||(h==n&&l!=m&&l%2==1)) {
			l++;
			f=1;
		}
		if(!f&&(l!=m||h!=n||l!=1||n!=1))
		{
			if(l%2==1) h++;
			else h--;
		}	
	}
	return 0;
}
