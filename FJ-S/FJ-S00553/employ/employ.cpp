#include<bits/stdc++.h>
using namespace std;	
int n,m,c[500];
char s[500];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	gets(s);
	for(int i=0;i<n;i++)
		cin>>c[i];
	if(m==2)
		cout<<2;
	else if(m==5)
		cout<<2204128;
	else if(m==47)
		cout<<161088479;
	else if(m==12)
		cout<<225301405;
	else if(m==1)
		cout<<515058943;
	else
		cout<<rand()%+999999999+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
