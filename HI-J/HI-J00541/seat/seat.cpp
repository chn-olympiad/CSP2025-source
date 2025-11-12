#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[15][15];
int b2[15][15];
int n,m;
int zz(int i,int j,int cnt1){
	cnt1--;
	b[i][j]=1;
	if(cnt1<=0){
		return j;
	}
	if(b[i+1][j]!=1&&i+1<=n&&j<=m&&i+1>0&&j>0){
		zz(i+1,j,cnt1);
	}
	if(b[i-1][j]!=1&&i-1<=n&&j<=m&&i-1>0&&j>0){
		zz(i-1,j,cnt1);
	}
	if(b[i][j+1]!=1&&i<=n&&j+1<=m&&i>0&&j+1>0){
		zz(i,j+1,cnt1);
	}
	
}
int z(int i,int j,int cnt){
	cnt--;
	b2[i][j]=1;
	if(cnt<=0){
		return i;
	}
	if(b2[i+1][j]!=1&&i+1<=n&&j<=m&&i+1>0&&j>0){
		z(i+1,j,cnt);
	}
	if(b2[i-1][j]!=1&&i-1<=n&&j<=m&&i-1>0&&j>0){
		z(i,j-1,cnt);
	}
	if(b2[i][j+1]!=1&&i<=n&&j+1<=m&&i>0&&j+1>0){
		z(i,j+1,cnt);
	}
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int xm=a[1];
	sort(a+1,a+n*m+1);
	int cnt=0;
	int js=0; 
	for(int i=n*m;i>0;i--){
		js++;
		if(a[i]==xm){
			cnt=js;
		}
	}
	int cnt1=cnt;
	int o=z(1,1,cnt);
	int oo=zz(1,1,cnt1);
	printf("%d %d",o,oo);
	return 0;
}

