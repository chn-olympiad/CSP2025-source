#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='0')
		{
			a[cnt]=s[i];
			cnt++;
		}
	}
	sort(a,a+n);
    for(int j=cnt;j>0;j--)
    {
    	cout<<a[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
