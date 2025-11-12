#include<bits/stdc++.h>
using namespace std;
int n,m,xi,a[10010];
int ch[101][101],x=1,y=1,num=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xi=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	while(num!=n*m){
		num++;
		ch[x][y]=a[num];
		if((y%2==1&&x+1>n)||(y%2==0&&x-1<1)){
			y++;
		}else if(y%2==1){
			x++;
		}else{
			x--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ch[i][j]==xi){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
