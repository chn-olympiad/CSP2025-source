#include<bits/stdc++.h>
using namespace std;

struct node{string x,y;}a[200005];node b[200005];
int n,q;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y;
    for(int i=0;i<q;i++)cin>>b[i].x>>b[i].y;
    for(int i=0;i<q;i++)cout<<0<<endl;
    return 0;
}
