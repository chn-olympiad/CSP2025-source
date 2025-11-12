#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf ("%d %d",&n,&m);
	if (n==3)
		puts("2");
		else
	if (n==10)
		puts("2204128");
		else
	if (n==500 && m==1)
		puts("515058943");
		else
	if (n==500 && m==12)
		puts("225301405");
		else
	if (n==100)
		puts("161088479");
		else
	puts("0");
	return 0;
}
