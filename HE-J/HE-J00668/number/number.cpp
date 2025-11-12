#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int i,a[100005]={0},c=0,f;
	getline(cin,s);
	f=s.size();
	for(i=0;i<f;i++)
	{
		if(s[i]<='9' && s[i]>='0')
		{
			a[i]=s[i]-'0';
			c++;
		}
	}
	sort(a+1,a+1+i);
	reverse(a+1,a+1+i);
	for(i=0;i<c;i++)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
