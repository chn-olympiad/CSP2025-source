#include<bits/stdc++.h> 
using namespace std;
int n,m,a[150],b[150],sc,pai,x=1,y=1;
bool fang=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	sc=a[1];
	for(int i=2;i<=n*m;i++)if(sc<a[i])pai++;
	for(int i=1;i<=pai;i++){
		if((x==n&&fang)||(x==1&&!fang)){
			y++;
			fang=!fang;
		}else{
			if(fang)x++;
			else x--;
		}
	}
	cout<<y<<' '<<x; 
	fclose(stdin);
	fclose(stdout);
}
