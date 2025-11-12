#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = s*10+ch-'0';
		ch = getchar();
	}
	return s*f;
}
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[1005],r,x,y,st[25][25];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n = read(),m = read();
	for(int i=1;i<=n*m;i++){
		a[i] = read();
	}
	r = a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(n%2 == 1){
			for(int j=1;j<=m;j++){
				st[i][j] = a[++cnt];
				if(a[cnt] == r){
					cout << i << " "<< j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				st[i][j] = a[++cnt];
				if(a[cnt] == r){
					cout << i << " "<< j;
					return 0;
				}
			}
		}
	}
	return 0;
}