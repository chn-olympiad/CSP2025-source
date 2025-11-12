#include<bits/stdc++.h>
using namespace std;

int n,m,cnt;
int a[120];

int main( ){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt++;
			cin>>a[cnt];
		}
	}
	int s=a[1],x=0,y=0;
	sort(a+1,a+cnt+1);
	while(1){
		x++;
		y++;
		for(;x<=n;x++){
			if(a[cnt]==s){
				cout<<y<<" "<<x;
				return 0;
			}
			cnt--;
		}
		x--;
		y++;
		for(;x>=1;x--){
			if(a[cnt]==s){
				cout<<y<<" "<<x;
				return 0;
			}
			cnt--;
		}
	}
	return 0;
}
