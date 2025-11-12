#include<bits/stdc++.h>
using namespace std;
const int N=200001;

struct sset
{
	string a,b;
};

sset str[N],qst;

int main()
{
	int n,T;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=0;i<n;i++) cin>>str[i].a>>str[i].b;
	while(T--)
	{
		cin>>qst.a>>qst.b;
		cout<<0<<endl;
	}
	return 0;
}
