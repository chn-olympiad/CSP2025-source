#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[150];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,i=1;
	while(k!=a[i]){
		if(y%2){
			if(x+1<=n){
				x++;
			}else{
				y++;
			}
		}else{
			if(x-1>=1){
				x--;
			}else{
				y++;
			}
		}
		i++;
	}
	cout<<y<<' '<<x;
	return 0;
}
