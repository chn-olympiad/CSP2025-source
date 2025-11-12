#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define maxn 1000005
using namespace std;
int a[maxn],k=1;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
	 	if(s[i]>='0'&&s[i]<='9')
	 	{
	 		a[k]=s[i]-'0';
	 		k++;
		}
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<k;i++)cout<<a[i];
	return 0;
}
