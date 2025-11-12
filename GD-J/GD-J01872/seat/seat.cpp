#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
long long n,m,a[maxn],dp[maxn][maxn],x,y,t;
bool flag=true;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
		t=a[1];
	}
	sort(a+1,a+1+n*m,cmp);
	x=1;
	y=1;
	for(int i=1;i<=n*m;i++){
		dp[x][y]=a[i];
		if(x+1<=n&&flag) x++;
		else if(x==n&&flag){
			y++;
			flag=false;
		}
		else if(x-1>=1&&!flag) x--;
		else if(x==1&&!flag){
			y++;
			flag=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]==t){
				printf("%lld %lld",j,i);
				return 0;
			}
		}
	}
	return 0;
}
