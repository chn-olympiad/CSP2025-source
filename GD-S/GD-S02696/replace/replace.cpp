#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	mt19937 rnd(45537);
	for(int i=1;i<=q;i++)cout<<rnd()%100000;
	return 0;
}
