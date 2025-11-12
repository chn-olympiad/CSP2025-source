#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int read();
int n,m,len,a[110],k,c;
bool cmp(int x,int y) {
	return x>y;
}
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n=read(),m=read();
	len=n*m;
	for(int i=1;i<=len;i++) {
		a[i]=read();
	}
	k=a[1];
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=m;i++) {
		if(i%2==1) {
			for(int j=1;j<=n;j++) {
				c++;
				if(a[c]==k) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else {
			for(int j=n;j>=1;j--) {
				c++;
				if(a[c]==k) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
int read(){
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9') {Cr=getchar();if(Cr=='-'){Cf=-1;}}
	while(Cr>='0' && Cr<='9') {Ca=Ca*10+Cr-48;Cr=getchar();}
	return Ca*Cf;
}
