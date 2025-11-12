#include<bits/stdc++.h>
using namespace std;
int s[60000];
int main()
{
	freopen("number.in ","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	int cnt=0,f=0;
	getline(cin,a);
	while(a[cnt]!=' ')
	{
		if(a[cnt]-'0'>=0 && a[cnt]-'0'<=9)
		{
			s[f]=a[cnt]-'0';
			f++;
		}cnt++;
	}
	cout<<f;
	sort(s+0,s+f);
	for(int i=f-1;i>=0;i--)
	{
		cout<<s[i];
	}	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
