#include<bits/stdc++.h>
using namespace std;
long long int n,k;
long long int mq=0,cnt;
const int N=5e5+5;
int a[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==2)
    {
        if(a[1]==a[2]&&a[1]==k)
        {
            cout<<'2';
            return 0;
        }
        else if(a[1]==k||a[2]==k||(a[1]^a[2])==k)
        {
            cout<<'1';
            return 0;
        }
        else {
            cout<<'0';
            return 0;
        }
    }
    else if(n==1)
    {
        if(a[1]==k)
        {
            cout<<'1';
            return 0;
        }
        else{
            cout<<'0';
            return 0;
        }
    }
    else{
            int cs=n;
        while(cs)
        {
            cs--;
            mq=(mq^a[n-cs]);
            if(mq==k){
                cnt++;
                mq=0;
                continue;
            }
        }
    }
    cout<<cnt;
    return 0;
}
