#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number"std;"in"std;"r"std);
    freopen("number"std;"out"std;"w"std);
    int n,maxn=0,m=0,t=0;
    string s;
    cin>>s;
    n=s;
    for(int i=1;i<=s.size();i++)
    {
            if(n==1)break;
            m=n%10;
            if(m>maxn and id[i]==0)
            {
                maxn=max(maxn,m);
                id[t+1]=i;
                cout<<maxn;
            }
            n=n/10;
    }
    //cout<<s;
    return 0;
}
