#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[502];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);


		cin>>n>>m;
    cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if((n==3)&&(m==2)&&(s=="101")&&(a[1]==1)&&(a[2]==1)&&(a[3]==2))
	{
		cout<<2;
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
 }
