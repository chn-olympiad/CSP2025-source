#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int x,y,flag=1;
	x=y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			cout<<x<<' '<<y<<endl;
			break;
		}
		y+=flag;
		if(y<1){
			y=1;
			x++;
			flag=1;
		}
		if(y>n){
			y=n;x++;flag=-1;
		}
	}
	return 0;
}