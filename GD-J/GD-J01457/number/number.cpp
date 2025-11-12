#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int i,j=0,len=s.size(),a[100000];
	for(i=0;i<len;i++)
		if(s[i]>='0' && s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
		}
	sort(a,a+j,greater<int>());
	for(i=0;i<j;i++)cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
