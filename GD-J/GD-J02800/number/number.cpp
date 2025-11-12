#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
string s;
int a[1919810],k,i;
int main()
{
	memset(a,0,sizeof(a));
	k=0;
	s=""; 
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (i=0; i<s.size(); i++)
		if (isdigit(s[i]))a[++k]=s[i]-'0';
	sort(a+1, a+1+k);
	while (a[k]==0 and k-1>=1) k--;
	for (i=k;i>=1;i--) cout << a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
