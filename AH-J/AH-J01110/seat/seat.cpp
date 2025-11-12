#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15],f[15][15],ss,sx,sy;
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
	ss=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,i=1;
	while(1){
		if(a[i]==ss){
		cout<<y<<" "<<x;
		return 0;
	}
	f[x][y]=1;
	if(x+1<=n&&f[x+1][y]==0){
		f[x+1][y]=1;
		x+=1;
	}else if(y+1<=m&&f[x][y+1]==0){
		f[x][y+1]=1;
		y+=1;
	}else if(x-1>=1&&f[x-1][y]==0){
		f[x-1][y]=1;
		x-=1;
	}
	i++;
	}
	return 0;
}
