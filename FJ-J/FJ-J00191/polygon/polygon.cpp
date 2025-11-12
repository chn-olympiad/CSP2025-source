#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s[110],max;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(i==1) max=s[i];
		else if(max<s[i]) max=s[i];
	}
	if(s[1]+s[2]+s[3]>max*2) cout<<"1";
	else cout<<"0";
	fclose(stdin);fclose(stdout);
	return 0;
}