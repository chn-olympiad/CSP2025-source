#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,a[105];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1],c=0,x=1,y=0;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(c==0){
			y++;
			if(y==n+1){
				y=n;
				x++;
				c=1;
			}
		}else {
			y--;
			if(y==0){
				y=1;
				x++;
				c=0;
			}
		}
		if(a[i]==s){
			cout<<x<<" "<<y;
			break;
		}
	}
	return 0;
}