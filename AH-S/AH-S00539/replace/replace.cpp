#include<bits/stdc++.h>
using namespace std;
long long n,q,cnt;
string a[200005],b[200005];
int main(void){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=q;i++)
    {
        cnt=0;
        string x,y;
        cin>>x>>y;
        for(int j=1;j<=n;j++)
        {
            long long t=x.find(a[j],0);
            for(;t!=-1;t=x.find(a[j],t+1))
            {
                string temp=x;
                temp=temp.substr(0,t)+b[j]+temp.substr(t+a[j].size());
                if(temp==y)cnt++;
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
