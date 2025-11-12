#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[100005];
bool cmp(int x,int y)
{
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			int h=0,l=i%n;
			if(i%n==0) h=i/n,l=n;
			else h=i/n+1,l=i%n;
			if(h%2==0) cout<<h<<" "<<n-l+1;
			else cout<<h<<" "<<l;
			return 0;
		}
	}
	return 0;
}
