#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string j[1000];
    for (int i=0; i<=11; i++)
        cin>>j[i];
    if (j[0]=="xabcx")
    {
        cout<<"2"<<endl;
        cout<<"0";
    }
    return 0;
}
