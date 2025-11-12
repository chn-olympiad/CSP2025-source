#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],b[1010][1010],x=1,y=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x%2==1){
			b[y][x]=a[i];
			y++;
			if(y>n){
				x++;
			}
		}
		else if(x%2==0){
			b[--y][x]=a[i];
			if(y==1){
				x++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==q){
				cout<<j<<' '<<i;
				return 0;
			} 
		}
		cout<<endl;
	}
	return 0;
}
