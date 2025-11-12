#include <bits/stdc++.h>
using namespace std;
int m,n,p,r,x=1,y=1,la;
int sc[105];
int se[105][105];
int flag[105][105]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	p=m*n;
	for(int i=1;i<=p;i++) {
		scanf("%d",&sc[i]);
	}
	r=sc[1];
	sort(sc+1,sc+p+1);
	la=p;
	for(int i=1;i<=p;i++) {
		se[x][y]=sc[la];
		if(se[x][y]==r)
		{
			cout << x << " " << y;
			return 0;
		}
		la--;
		if((y==n&&x%2==1)||(y==1&&x!=1&&x%2==0)){
			x++;
		}
		if(y==n&&flag[x][y]==0){
			y++;
			flag[x][y-1]=1;
		}
		if(y==1&&x!=1&&flag[x][y]==0){
			y--;
			flag[x][y+1]=1;
		}
		if(x%2==1 && y!=n) {
			y++;
		}
		else if(x%2==0&&(y!=1&&x!=1)){
			y--;
		}
	}
	return 0;
}
