#include<bits/stdc++.h>
using namespace std;
int lst[500010],top=1,ans=0;
void change(int x,int k)
{
    for(int i=1;i<top;i++)
    {
        lst[i]=( lst[i] ^ x );
        if(lst[i]==k)
        {
            ans++;
            top=1;
            return;
        }
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        lst[top]=0;
        top++;
        change(x,k);
    }
    cout<<ans;
    return 0;
}
/*
*/
