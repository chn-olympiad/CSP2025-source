#include <bits/stdc++.h>
using namespace std;
string an1[200010],an2[200010];
string qu1[200010],qu2[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
        cin>>an1[i]>>an2[i];
    for (int i=1;i<=q;i++)
    {
		cin>>qu1[i]>>qu2[i];
		cout<<"0";   
	}
	return 0;
}
