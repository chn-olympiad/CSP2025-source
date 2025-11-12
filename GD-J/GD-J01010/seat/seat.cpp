#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=0,y=1,flag=1;
	for(int i=1;i<=n*m;i++){
		x+=flag;
		if(x>n){
			x--;
			flag*=-1;
			y++;
		}
		if(x<1){
			x++;
			flag*=-1;
			y++;
		}
		if(a[i]==t){
			cout<<y<<' '<<x<<'\n';
			return 0;
		}
			
	}
	return 0;
}

