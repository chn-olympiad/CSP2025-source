#include<string>
#include<iostream>
using namespace std;
long long n,m,c[505],ans;
string s;
bool a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=0;i<n;i++)
		if(s[i]=='0')
		{
			a=1;
			break;
		}
	for(int i=1;i<=n;i++)
		ans*=i;
	cout<<ans<<endl;
	return 0;
}
