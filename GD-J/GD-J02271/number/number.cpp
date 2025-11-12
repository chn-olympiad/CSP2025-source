#include<bits/stdc++.h>
using namespace std;
int a[1000001]={0},n=0,f;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	f=s.size();
	for(int i=0;i<f;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n++;
			a[i]=int(s[i])-48;
		}
	}
	sort(a,a+f);
	for(int j=f-1;j>=f-n;j--)
		cout<<a[j];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
