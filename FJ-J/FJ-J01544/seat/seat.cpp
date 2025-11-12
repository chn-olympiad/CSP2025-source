#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010],s[15][15];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main (){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int xxx;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xxx=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(xxx==a[i]){
			xxx=i;
			break;
		}
	}
	int t=1,x=1,y=1;
	while(t<=n*m){
		while(y<=n&&t<=n*m){
			s[x][y]=t;
			if(s[x][y]==xxx){
				cout<<x<<" "<<y;
				return 0;
			}
			t++;
			y++;
		}
		x++;
		y--;
		while(y>=1&&t<=n*m){
			s[x][y]=t;
			if(s[x][y]==xxx){
				cout<<x<<" "<<y;
				return 0;
			}
			t++;
			y--;
		}
		x++;
		y++;
	}
	return 0;
}
