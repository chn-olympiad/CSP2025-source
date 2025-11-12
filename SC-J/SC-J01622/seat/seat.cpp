#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R)break;
		if(y%2==1){
			x++;
			if(x>n){
				x=n,y++;
			}
		}else{
			x--;
			if(x<1){
				x=1,y++;
			}
		}
	}
	cout<<y<<' '<<x<<endl;
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

*/