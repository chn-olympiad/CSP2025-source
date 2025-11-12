#include<bits/stdc++.h>
using namespace std;
int cmp(char q,char w)
{
	return q>=w;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000005];
	int d=0;
	cin>>s;
//    scanf("%s",&s);
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i];
		
			d++;
		}
	}

	sort(a,a+d,cmp);
	for(int i=0;i<=d;i++)
	{
		if(i==0&&a[i]==0)
		{
			cout<<0;
			return 0;
		}
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
}
