#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1001],n,m,num,s;//s记录下标 
int mapp[11][11];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
		cin>>a[i];
	num=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;++i)
		if(a[i]==num){
			s=i;
			break; 
		}
	int x,y;
	x=(s-1)/n+1;
	if(x%2==0)
		y=n*x-s+1;
	else
		y=n-n*x+s;
	cout<<x<<' '<<y;
	return 0;
}