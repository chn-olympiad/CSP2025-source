#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[1010],cnt=1,lie,pai;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	for(int i=2;i<=n*m;++i)
	{
		if(a[i]>a[1]) ++cnt;
	}
//	cout<<cnt;
	lie=cnt/n+(cnt%n!=0);
	pai=cnt-(lie-1)*n;
//	cout<<lie<<" "<<pai;
	if(lie&1) cout<<lie<<" "<<pai;
	else cout<<lie<<" "<<n+1-pai;
	return 0;
}
