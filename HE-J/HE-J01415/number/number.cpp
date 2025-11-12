#include <bits/stdc++.h>
using namespace std;
int cnt,x=1;
int a[1000050];
int b[1000050];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;;i++)
	{
		if(!s[i])break;
		else 
		{
			cnt++;
			a[i]=s[i]-48;
			if(a[i]>=0&&a[i]<=9)b[x]=a[i],x++;
		}
	}
	sort(b+1,b+x+1);
	//cout<<cnt<<endl;
	for(int i=x;i>1;i--)cout<<b[i];

	return 0;
}


