#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,q;
string s1[200010],s2[200010];
string t1[200010],t2[200010];
int main(int argc, char** argv)
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)cin>>t1[i]>>t2[i];
	return 0;
}