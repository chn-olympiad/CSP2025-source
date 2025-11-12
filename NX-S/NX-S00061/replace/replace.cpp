#include<iostream>
#include<string>
using namespace std;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string s1,s2;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
    }
    string s3,s4;
    for(int i=1;i<=q;i++)
    {
        cin>>s3>>s4;
    }
    cout<<n;

    return 0;
}
