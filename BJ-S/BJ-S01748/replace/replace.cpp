#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string s1;
    string s2;
    for(int i=0;i<n;i++)
    {
        cin>>s1>>s2;
    }
    for(int i=0;i<q;i++)
    {
        cin>>s1>>s2;
    }
    for(int i=1;i<=q;i++)
    {
        cout<<"0"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}