#include<bits/stdc++.h>
using namespace std;
const int MAXN=100+5;
int n,m,ans[MAXN][MAXN],a[MAXN*MAXN],rs;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1){
			rs=a[i];
		}
	}
	sort(a+1,a+n*m+1,greater<int>());
	int x=1,y=0;
	bool flag=0;
	for(int i=1;i<=n*m;i++){
		if(!flag){
			y++;
			if(y>n){
				y=n;
				x++;
				flag=1;
			}
		}else{
			y--;
			if(y==0){
				y=1;
				x++;
				flag=0;
			}
		}
		ans[x][y]=a[i];
		if(a[i]==rs){
			printf("%d %d",x,y);
			break;
		}
	}
	
	return 0;
}
