#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000006]; 
bool cmp(int x,int y)
{
	 return (x<y); 
} 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int le=s.size(),an=0;
	for(int i=0;i<le;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			an++;
			a[an]=s[i]-'0'; 
		}
	} 
	sort(a+1,a+an+1,cmp);
	while(an!=1&&a[an]==0)	an--;	 
	for(int i=an;i>=1;i--)	cout<<a[i]; 
	return 0;
}
