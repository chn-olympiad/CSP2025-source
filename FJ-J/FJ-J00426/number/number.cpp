#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int a[n+1]={0};
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sum+=1;
			a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1);
	if(sum==0) cout<<-1;
	for(int i=sum;i>=1;i--) cout<<a[i];
}
//¸øµã·Ö°É 

