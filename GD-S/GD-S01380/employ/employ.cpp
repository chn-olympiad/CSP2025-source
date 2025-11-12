#include<iostream>
using namespace std;
const int MAXN = 505;
const long long MOD = 998244353;
int c[MAXN];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool flagA = true;
	for(char ch:s)
		if(ch != '1')
			flagA = false;
	cout<<n<<endl;
	int tmp = n;
	n= 0;
	for(int i = 1;i <= tmp;i++)
	{
		int j;
		cin>>j;
		if(j != 0)
		{
			n++;
			c[n] = j;
		}
	}
	cout<<m<<endl;
	if(flagA == true)
	{
		long long sum = 1;
		for(int i = m;i >= 1;i--)
			sum=(sum*i)%MOD;
		cout<<sum;
	}
	return 0;
}
