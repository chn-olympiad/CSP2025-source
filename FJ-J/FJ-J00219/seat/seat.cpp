#include <bits/stdc++.h>
using namespace std;
const int N=133,M=13;
int n,m,a[N],b[M][M],num;
inline bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>m>>n;
	for(int i=1;i<=n*m;i++)cin >>a[i];
	num=a[1],sort(a+1,a+1+n*m,cmp);
	if(m%2==0)b[1][m]=-1;
	else b[n][m]=-1;
	int x=1,y=1,d=1,cnt=1;
	while(b[y][x]!=-1){
		b[y][x]=cnt++,y+=d;
		if(b[y][x]==-1)break;
		if(y==n&&d==1)b[y][x]=cnt++,d=-1,x++;
		else if(y==1&&d==-1)b[y][x]=cnt++,d=1,x++;
	}
	b[y][x]=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(num==a[b[i][j]]){
				cout <<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
