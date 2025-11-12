#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int seat[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1;
	for(int x=1;x<=m;x++){
		if(x%2){
			for(int y=1;y<=n;y++){
				seat[x][y]=a[i];
				if(a[i]==R){
					cout<<x<<' '<<y;
					return 0;
				}
				i++;
			}
		}
		else{
			for(int y=n;y>=1;y--){
				seat[x][y]=a[i];
				if(a[i]==R){
					cout<<x<<' '<<y;
					return 0;
				}
				i++;
			}
		}
	}
	return 0;
}//密码的要我调那么久 思慕小蛋糕 
