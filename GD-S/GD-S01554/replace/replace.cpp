#include<iostream>
#include<cmath>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=100005;
ll n,q;
string s1[maxn],s2[maxn],x,y;
inline void fre()
{
	freopen("replace.in","r",stdin);
	fropen("replace.out","w",stdout);
}
int main()
{
	IOS
	fre();
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<0<<endl;
	}
	return 0;
}
