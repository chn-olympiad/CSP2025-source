#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int sum;
int ans;
struct node
{
    int num;
    int val;
    bool tag=false;
}a[1000001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].val;
        a[i].num=i;
        if(a[i].val==k)
            ans++;
    }
    cout<<ans;
    return 0;
}
