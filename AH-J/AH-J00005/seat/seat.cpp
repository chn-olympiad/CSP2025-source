#include<bits/stdc++.h>
using namespace std;
int a[100005],f[105][105],n,m,x=1,y=1,q;
void rec(){
	for(int i=1;i<=n*m;i++){
	f[x][y]=a[i];
	 if(x+1<=n&&f[x+1][y]==0)x++;
	 else if(x-1>=1&&f[x-1][y]==0)x--;
	 else if(y+1<=m&&f[x][y+1]==0)y++;
	}
}
bool cmp2(int a,int b){
	return a>b;
}
void find(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]==q){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	q=a[1];
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=0;
		}
	}
	sort(a+1,a+1+n*m,cmp2);
	rec();
	find();
return 0;
}
//3 3
//94 95 96 97 98 99 100 93 92
