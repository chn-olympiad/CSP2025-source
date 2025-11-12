#include<bits/stdc++.h> 
using namespace std;
string s;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k++;
			a[k]=s[i]-'0';
			
		}
	}
	sort(a+1,a+k+1);
	if(a[k]==0)
	{
		cout<<0;
	}
	else
	{
		for(int i=k;i>0;i--)
		{
			cout<<a[i];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
