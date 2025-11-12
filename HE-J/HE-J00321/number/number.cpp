#include<bits/stdc++.h>
using namespace std;
string a;
int x[130];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
		x[a[i]]++;
	for(int i=57;i>=48;i--)
		for(int j=1;j<=x[i];j++)
			printf("%d",i-48);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
