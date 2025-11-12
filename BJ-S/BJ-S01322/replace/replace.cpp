#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,q;
pair<string,string>s[N];
bitset<N*5>A,B;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].first>>s[i].second;
    }
    for(int o=1;o<=q;o++)
    {
        string x,y;
        cin>>x>>y;
        if(x.size()!=y.size())
        {
            cout<<"0\n";
            continue;
        }
        A.reset(),B.reset();
        for(int i=0;i<x.size();i++)
        {
            if(x[i]==y[i])A[i]=1;
            else break;
        }
        for(int i=x.size()-1;i>=0;i--)
        {
            if(x[i]==y[i])B[i]=1;
            else break;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int pos=-1;
            while(1)
            {
                pos=x.find(s[i].first,pos+1);
                if(pos<0)break;
                //cout<<x<<' '<<s[i].first<<' '<<s[i].second<<'\n';
                //cout<<x.substr(0,pos)+s[i].second+x.substr(pos+s[i].first.size())<<'\n';
                if(pos-1>=0&&(!A[pos-1]))continue;
                if(pos+s[i].first.size()<n&&(!B[pos+s[i].first.size()]))continue;
                if(s[i].second==y.substr(pos,s[i].first.size()))cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
