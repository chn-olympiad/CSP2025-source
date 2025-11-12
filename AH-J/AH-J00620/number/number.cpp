#include<bits/stdc++.h>
using namespace std;
char a[1000010];
bool cmp(int c,int d)
{
	return c>=d;
}	
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=1;
	int len=s.size();
	for(int i=0;i<=len;i++)
		if(s[i]>='0' && s[i]<='9') 
		{
			a[j]=s[i];
			j++;
		}
	j-=1;
	sort(a+1,a+1+j,cmp);
	for(int i=1;i<=j;i++)
		cout<<a[i];
	cout<<endl;
	return 0;
}
