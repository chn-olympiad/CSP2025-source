#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[110],b,c,x,y;
bool cmp(int o,int p){
	return o>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++) if(a[i]==c) b=i;
	x=(b-1)/n+1;
	cout<<b<<" "<<c<<endl;
	if(x%2==1) y=(b-1)%n+1;
	else y=n-(b-1)%n;
	cout<<x<<" "<<y;
	return 0;
}//4 5 19 1 2 3 4 5 6 8 9 10 11 7 13 14 15 16 17 18 12 20
