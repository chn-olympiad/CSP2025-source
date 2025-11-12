#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
void read(int &a) {
	a=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-') {
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		a=a*10+c-48;
		c=getchar();
	}
	a*=f;
}
void wr(int a) {
	if(a>9) {
		wr(a/10);
	}
	putchar(a%10+48);
}
void write(int a) {
	if(a<0) {
		a=-a;
	}
	wr(a);
	putchar('\n');
}
int n,k;
int a[N],maxn=-INT_MAX;
bool fg,fg1;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n);
	read(k);
	for(int i=1; i<=n; i++) {
		read(a[i]);
		maxn=max(maxn,a[i]);
		if(a[i]!=0) {
			fg=1;
		}
		if(a[i]>1) {
			fg1=1;
		}
	}
	if(k==0&&fg==0) {
		write(n/2);
		return 0;
	}
	if(fg1==0) {
		int sum=0;
		if(k==0) {
			for(int i=1; i<=n; i++) {
				if(a[i]==1&&a[i-1]==1) {
					sum++;
					a[i]=2;
					a[i-1]=2;
				} else if(a[i]==0) {
					sum++;
				}
			}
		} else {
			for(int i=1; i<=n; i++) {
				if(a[i]==1) {
					sum++;
				}
			}
		}
		write(sum);
		return 0;
	}
	if(maxn<k) {
		write(0);
		return 0;
	}else{
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				sum++;
			}
		}
		write(sum);
	}
	return 0;
}
