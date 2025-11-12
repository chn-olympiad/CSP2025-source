#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510;
int n,m;
string s;
int c[N];
int su=1;
int cnt;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
		{
			cnt++;
		}
	}
	//for(int i=0;i<s.size;i++)
	//{
	//	i)
	//}
	for(int i=n;i>cnt;i--)
	{
		su=su%998244353*i;
		su=su%998244353;
		//cout<<su<<" ";
	}
	//su%=;
	cout<<su;
	return 0;
}
