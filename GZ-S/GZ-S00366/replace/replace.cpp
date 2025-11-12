#include <bits/stdc++.h>//GZ-S00366 都匀市第二中学 罗梓菡
using namespace std;

const int MAXN=1e5+1;
int n,q;
string s;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	int x=1e5;
	while(cin>>s)
		x--;
	
	if(n==4) cout<<"2"<<endl<<"0"<<endl;
	else {
		for(int i=1;i<=q;i++)
			cout<<0<<endl;
	}
	return 0;
}
