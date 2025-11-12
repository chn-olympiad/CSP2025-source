#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int v=a[1];
	int po;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==v){
			po=i;
			break;
		}
	}
	po=n*m-po+1;
	int f=1;
	int x=0,y=1;
	while(1){
		po--;
		x++;
		if(x>n){
			x-=n;
			y++;
			f=1-f;
		}
		if(po==0){
			break;
		}
	}
	if(f==0)x=n-x+1;
	cout<<y<<" "<<x<<endl;
	return 0;
} 
/*
2 2
99 100 97 98
*/
/*
2 2
98 99 100 97
*/
/*
3 3
94 95 96 97 98 99 100 93 92
*/