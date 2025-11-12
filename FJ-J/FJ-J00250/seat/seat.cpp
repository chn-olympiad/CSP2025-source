#include<bits/stdc++.h>
using namespace std;
int n,m,t,x,y;
int a[105],s[15][15];

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
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int id;
			if(j%2!=0){
				id=(j-1)*n+i;
			}
			else{
				id=(j-1)*n+n-i+1;
			}
			s[i][j]=a[id];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==t){
				x=i,y=j;
			}
		}
	}
	cout<<y<<" "<<x<<"\n";
	return 0;
}
