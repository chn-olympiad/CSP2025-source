#include <bits/stdc++.h>
using namespace std;

int a[10000];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m,n;
	cin>>n>>m;
	int xh;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		xh=a[0];
	}
	sort(a,a+n*m);
	int ff=0;
	int x=1,y=1;//x=m,y=n
	for(int i=n*m-1;i>=0;--i){
		if(a[i]==xh){
			cout<<x<<" "<<y;
			return 0;
		}
		if(x%2==1){
			y++;
			if(y>m){
				x++;
			}
		}//else
		if(x%2==0){
			y--;
			if(y<1){
				x++;
				y++;
			}
		}
	}
	return 0;
} 