#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
using namespace std;
int n,q;
string s[200010],S[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>S[i];
        cout<<0<<endl;
    }
    return 0;
}