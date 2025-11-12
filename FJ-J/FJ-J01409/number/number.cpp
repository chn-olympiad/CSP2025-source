#include<bits/stdc++.h>
 
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

 	int x=0;
	char s[1000000]="";
	int a[1000];
	
	cin>>s;
		
	for(int i=0;i<=1000000-1;i++)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			a[x] = s[i]-'0';
			x++;
		}
	}
	sort(a+0,a+x);
	for(int j=x-1;j>=0;j--) cout<<a[j];

	fclose(stdin);
	fclose(stdout);
	return 0;
}
