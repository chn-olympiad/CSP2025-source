#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],b[15][15],pos;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	pos=a[1];
	int d=n*m;
	sort(a+1,a+d+1,cmp);
	int x=1,y=1,f=1;
	for(int i=1;i<=n*m;i++){
		if(x<1){
			y++;
			x=1;
			f=-f;
		}
		if(x>n){
			y++;
			f=-f;
			x=n;
		}
		b[x][y]=a[i];
		x+=f;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==pos){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
