#include<bits/stdc++.h>
using namespace std;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int s=0
    cin>>n>>q;
    string s[3],t[3];
    for(i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	for(i=1;i<=q ;i++)
		cin>>t[i][1]>>t[i][2]
	for(i=1;i<=n;i++)
		for(j=1;j<=q;j++)
			if(s[i][1]==t[i][1]&&s[i][2]==t[i][2]
				s+=2;
	cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
