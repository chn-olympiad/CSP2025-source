#include<bits/stdc++.h>
using namespace std;
string s1;
int cnt;
int a[100005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s1;
	int len=s1.size();
	for(int i=0;i<len;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			cnt++;
			a[i]=s1[i]-'0';
		}
	}
	sort(a,a+len);
	for(int i=len-1;i>=len-cnt;i--)
	{
		cout<<a[i];
	}
	 
	
	
	return 0;
} 
