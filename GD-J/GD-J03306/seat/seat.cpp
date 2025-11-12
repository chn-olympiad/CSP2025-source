#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105;
int n,m,k,x=1,y=1,id,a[N];
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)cin>>a[i];
	id=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++)
	{
		if(a[i]==id)
		{
			cout<<x<<" "<<y;
			return 0;
		}
		if(x%2==1)
		{
			y++;
			if(y==n+1)y=n,x++;
		}
		else 
		{
			y--;
			if(y==0)y=1,x++;
		}
	}
	return 0;
}

