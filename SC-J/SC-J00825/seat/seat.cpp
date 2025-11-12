#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],b[105];
int qwe(int x,int y){
	if(a[x+1][y]==0){
		return 2;
	}else if(a[x-1][y]==0){
		return 1;
	}else if(a[x][y+1]==0){
		return 3;
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int p=b[1],t;
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(b[i]==p){
			t=i;
			break;
		}
	}
	t=n*m-t+1;
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			if(i==0||j==0|i==n+1||j==m+1){
				a[i][j]=114514;
			}
		}
	}
	int x=1,y=1,pd;
	a[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			pd++;
			if(pd==t){
				cout<<y<<" "<<x;
				return 0;
			}
			if(qwe(x,y)==0){
			}else if(qwe(x,y)==1){
				x--;
			}else if(qwe(x,y)==2){
				x++;
			}else if(qwe(x,y)==3){
				y++;
			}
			a[x][y]=pd;
		}
	}
	return 0;
}
