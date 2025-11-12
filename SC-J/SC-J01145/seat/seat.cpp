#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a,s[15][15],b[110],c[110];
long long xm,k=1,jsq=0;

void f(int x,int y,int k){
	s[x][y]=k;
	if(x+1<=n&&s[x+1][y]==0){
		f(x+1,y,k+1);
	}else if(x-1>=1&&s[x-1][y]==0){
		f(x-1,y,k+1);
	}else if(y+1<=m&&(x==1||x==n)&&s[x][y+1]==0){
		f(x,y+1,k+1);
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n*m;i++){
		scanf("%lld",&a);
		if(i==1) xm=a;
		b[a]++;
	}
	for(long long i=110;i>=1;i--){
		if(b[i]!=0){
			for(long long j=1;j<=b[i];j++){
				jsq++;
				c[jsq]=i;
			}
		}
	}
	for(long long i=1;i<=n*m;i++){
		if(c[i]==xm){
			k=i;
			break;
		}
	}
	f(1,1,1);
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(s[i][j]==k){
				printf("%lld %lld",j,i);
				return 0;
			}
		}
	}
	return 0;
}