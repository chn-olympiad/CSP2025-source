#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int num=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9') 
		{
			a[num]=s[i]-48;
			num++;
		}
	}
	sort(a,a+num);
	reverse(a,a+num);
	for(int i=0;i<num;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
