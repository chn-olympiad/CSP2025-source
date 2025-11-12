#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int s;
int seat[20][20];
bool cmp(int x,int y){
	return x>y;
}
void pai(int x,int y,int num){
	seat[y][x]=a[num];
	if(num==n*m){
		return ;
	}if(y==1 && x%2==0){
		pai(x+1,y,num+1);
		return ;
	}else if(y==n && x%2){
		pai(x+1,y,num+1);
		return ;
	}else if(x%2){
		pai(x,y+1,num+1);
		return ;
	}else if(x%2==0){
		pai(x,y-1,num+1);
		return ;
	}return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("saet.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	pai(1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==s){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
