#include<bits/stdc++.h>
using namespace std;
int a[110][110],c[10010],ans=0;
bool yd=false,xd=true,sx=false;
bool cmp(int d,int b){
	return d>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> c[i];
	}
	ans=c[1];
	sort(c+1,c+n*m+1,cmp);
	int x=1,y=1,s=1;
	while(s<=n*m){
		a[x][y]=c[s];
		if(x==m&&sx==false || x==1&&sx==true){
			yd=true;
			xd=false;
			sx=!sx;
		}
		if(yd==true){
			y+=1;
			xd=true;
			yd=false;
		}else if(xd==true){
			if(sx==false){
				x+=1;
			}else{
				x-=1;
			}
		}
		s+=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==ans){
				cout << j << ' '<<i;
				return 0;
			}
		}
	}
	return 0;
}