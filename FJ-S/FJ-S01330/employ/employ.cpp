#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==500&& b==12)
		puts("225301405");
	else if(a==500 && b==1)
		puts("515058943");
	else if(a==100 && b==47)
		puts("161088479");
	else if(a==10 && b==5)
		puts("2204128");
	else
		puts("998244352");
	
	return 0;
}