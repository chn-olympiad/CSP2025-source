#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5+10;
int n,m,a[maxn];
bool cmd(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x1=a[1];
	sort(a+1,a+n*m+1,cmd);
	int x=0;
	for(int i=1;i<=n*m;i++)if(a[i]==x1)x=i;
	for(int i=1;i<=m;i++){
		if(x<=n){
			cout<<i<<' ';
			if(i&1)cout<<x;
			else cout<<n-x+1;
			break;
		}
		x-=n;
	}
	return 0;
}
