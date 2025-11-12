#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
struct s{
	string c,b;
}a[1000100];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].b>>a[i].c;
	}
	while(m--)
	{
		int cnt=0;
		string x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++) 
		{
			if(x==a[i].b&&y==a[i].c)
			{
				cnt++;
			}
			if(x.find(a[i].b)==0&&y.find(a[i].c)==0)
			{
				cnt++;
			}
		}
		if(cnt==1){
			cout<<0<<endl; 
			continue;
		}
		cout<<cnt<<endl;
	}
	return 0;
} /*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
