#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,m;//来应聘的人数和希望录用的人数 
string s; 
int c[510];
const int MOD=998244353;
void over(int i)
{
	for(;i<=n;i++)
	{
		c[i]--;	
	}
}
int main(int argc, char** argv)
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		if()
	}
	return 0;
}