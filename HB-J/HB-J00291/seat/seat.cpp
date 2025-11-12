#include<bits/stdc++.h>
using namespace std;

int read(){
	int w = 1,s = 0;
	char ch = getchar();
	while(ch<48||ch>57){
		if(ch=='-')w = -1;
		ch = getchar();
	}
	while(ch>=48&&ch<=57){
		s = (s<<1)+(s<<3)+(ch^48);
		ch = getchar();
	}
	return w*s;
}

const int N = 20;

int a[N][N],val[N*N],R,n,m,sor = 1,cnt = 0;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n*m;++i){
		val[i] = read();
	}
	R = val[1];
	sort(val+1,val+1+n*m,cmp);
	for(int j = 1;j <= m;++j){
		if(sor==1){
			for(int i = 1;i <= n;++i){
				cnt++;
				a[i][j] = val[cnt];
			}
		}
		else{
			for(int i = n;i >= 1;i--){
				cnt++;
				a[i][j] = val[cnt];
			}
		}
		sor = !sor;
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			if(a[i][j]==R){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}