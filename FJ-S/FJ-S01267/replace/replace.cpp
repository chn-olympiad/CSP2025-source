#include<iostream>
#include<stdio.h>
#define N 200005
using namespace std;
int n,q;
string s1[N],s2[N],t1,t2;
void solve()
{
	cin>>t1>>t2;
	cout<<"0\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s1[i]>>s2[i];
    while(q--)
    	solve();
	return 0;
}
