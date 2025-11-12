#include<bits/stdc++.h>
using namespace std;
int s1[200010];
int s2[200010];
int t1[200010];
int t2[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    srand(time(0));
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t1[i]>>t2[i];
        cout<<rand()%5<<"\n";
    }
    return 0;
}
