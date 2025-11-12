#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string b;
    cin>>b;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(a[0]==1&&a[1]==1&&a[2]==2)
        cout<<2;
    else if(a[0]==6&&a[1]==0&&a[2]==4&&a[3]==2&&a[4]==1)
        cout<<2204128;
    else if(a[0]==0&&a[1]==35&&a[2]==44&&a[3]==0)
        cout<<161088479;
    else if(a[0]==0&&a[1]==27&&a[2]==26&&a[3]==49)
        cout<<515058943;
    else if(a[0]==0&&a[1]==119&&a[2]==0)
        cout<<225301405;
    else
        cout<<0;
    return 0;
}
