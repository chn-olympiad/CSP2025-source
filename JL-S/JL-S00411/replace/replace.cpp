#include<bits/stdc++.h>
using namespace std;
set<int> a;
int n,x;
int main()
{
	freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		cin>>n;
for(int i=1;i<=n;i++)
{
cin>>x;
a.insert(x);
}
for(auto c:a)
cout<<c<<" "<<endl;
	return 0;
}
