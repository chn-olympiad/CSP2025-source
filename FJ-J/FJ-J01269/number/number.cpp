#include<bits/stdc++.h>
using namespace std;
string s;
int k[1001010],sum;
bool cmp(int x1,int x2)
{
	return x1>x2;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char i:s) if(isdigit(i)) k[++sum]=i-'0';
	sort(k+1,k+1+sum,cmp);
	for(int i=1;i<=sum;i++)
	  cout<<k[i];
	return 0;
}
