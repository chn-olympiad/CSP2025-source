#include <bits/stdc++.h>
using namespace std;
string s;
long long b[1000005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("number.in ","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int sums=0;
	if(len==1&&(int)s[0]<'a')
	{
		cout<<s[0];
		return 0;
	}
	for(int i=0,j=0;i<len;i++)
	{
		if((int)s[i]>=48&&(int)s[i]<97)
		{
			b[j]=((int)s[i])-'0';
			j++;
			sums++;
		}
	}
	sort(b,b+sums);
	long long res=0;
	long long t=sums;
	for(int i=sums-1;i>=0;i--)
	{
		if(t==1)
		{
			res+=b[0];
			break;
		}
		long long minn=pow(10,t);
		res+=b[t]*minn;
		t--;
	}
	cout<<res<<endl;
	return 0;
}
