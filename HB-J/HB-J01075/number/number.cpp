#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10],j=1;
	cin>>s;
	int k=s.size();
	for(int i=0;i<k;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
		}	
	}
	j--;
	sort(a+1,a+j+1);
	int ans=0;
	for(int i=j;i>=1;i--)
	{
		ans*=10;
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
