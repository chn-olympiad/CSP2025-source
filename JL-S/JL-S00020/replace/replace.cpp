#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int i,j,n,q,cnt=0,t=0;
    string w[10000],s[10000];
    cin>>n>>q;
    for(i=0;i<n*2;i++)
        cin>>w[i];
    for(j=0;j<q*2;j++)
        cin>>s[j];
    if(n<=q)
    {
        for(i=0;i<n*2;i++)
        {
            if(w[i]==s[i])
                cnt++;
            t++;
            if(t==2)
            {
                t=0;
                cout<<cnt<<endl;
                cnt=0;
            }
        }
    }
    else
    {
       for(i=0;i<n*2;i++)
        {
            for(j=0;j<q*2;j++)
            {
                if(w[i]==s[j])
                    cnt++;
            }
            if(i%4==3)
            {
                cout<<cnt<<endl;
                cnt=0;
            }
        }
    }
    return 0;
}
