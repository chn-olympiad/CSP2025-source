#include "bits/stdc++.h" 
using namespace std;
const int N=1e6+10;
string s;
int n,m;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j;
	getline(cin,s);
	
	for(i=0;i<s.size();i++)
	{
		if(isdigit(s[i]) )a[(s[i]-'0')]++;
	}
	for(i=9;i>=0;i--)
	{
		while(a[i]--) cout<<i;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
	
	
	
}
