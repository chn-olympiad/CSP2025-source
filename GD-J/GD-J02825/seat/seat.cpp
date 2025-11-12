#include <bits/stdc++.h>
using namespace std;
#define For(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
const int M=100101;
const int inf=1e9+7;
int n,m,ans,a[M];
int x,y;
bool b;
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	For(i,1,n*m) scanf("%d",&a[i]);
	ans=n*m;
	sort(a+2,a+2+n*m,cmp);
	For(i,2,n*m){
		if(a[i]<a[1]){
			ans=i-1;break;
		}
	}
//	printf("%d ",ans);
	x=1;y=1;
	For(i,1,ans-1){
		if(!b){
			if(y==m){x++;b=1;}
			else y++;
		}
		else{
			if(y==1){x++;b=0;}
			else y--;
		}
	}
	printf("%d %d",x,y);
	return 0;
}
/*
3 3
10 2 3 4 5 6 7 8 9
*/
