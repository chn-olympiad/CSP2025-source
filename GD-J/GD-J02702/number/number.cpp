#include<bits/stdc++.h>//#Shang4Shan3Ruo6Shui4
#define ll long long
#define endl "\n"
using namespace std;
int a[1000005],sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;int len;
	cin>>s;len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')a[++sum]=s[i]-'0';
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--)cout<<a[i];
	return 0;
}
