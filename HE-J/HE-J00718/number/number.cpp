#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[1000010],k;
bool cmp(int a,int b)
{
	if(a>=b) return true;
	else if(a<b) return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
