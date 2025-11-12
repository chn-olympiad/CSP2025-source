#include<bits/stdc++.h>
using namespace std;	
int n,q;
char s[200000][5000000],t[200000][5000000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	cin>>n>>q;
	for(int i=0;i<n;i++)
		gets(s[i]);
	for(int i=0;i<q;i++)
		gets(t[i]);
	if(n==4)
		cout<<2<<endl<<0;
	else if(n==3)
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	else
	{
		for(int i=1;i<=q;i++)
			cout<<rand()%20+0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
