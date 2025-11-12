#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005],b[200005];
vector<int> bda[200005];
vector<int> bdb[200005];
string x,y;
queue<int> ansx,ansy;
int ans;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        bda[i].resize(a[i].size()+5);
        bda[i][0]=0;
        for(int j=1;j<a[i].size();j++)
        {
            if(a[i][j]==a[i][bda[i][j-1]])
                bda[i][j]=bda[i][j-1]+1;
        }
        bdb[i].resize(b[i].size()+5);
        bdb[i][0]=0;
        for(int j=1;j<b[i].size();j++)
        {
            if(b[i][j]==b[i][bdb[i][j-1]])
                bdb[i][j]=bdb[i][j-1]+1;
        }
    }
    while(q--)
    {
        ans=0;
        cin>>x>>y;
        if(x.size()!=y.size())
        {
            cout<<"0\n";
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            while(!ansx.empty())ansx.pop();
            while(!ansy.empty())ansy.pop();
            for(int j=0,p=0;j<x.size();j++,p++)
            {
                //cout<<p<<' ';
                if(x[j]!=a[i][p])
                {
                    p--;
                    if(p>=0)p=bda[i][p];
                    else p=-1;

                }
                else if(p==a[i].size()-1)
                {
                    p=-1;
                    ansx.push(j-a[i].size()+1);
                }
            }
            for(int j=0,p=0;j<y.size();j++,p++)
            {
                if(y[j]!=b[i][p])
                {
                    p--;
                    if(p>=0)p=bdb[i][p];
                    else p=-1;
                }
                else if(p==b[i].size()-1)
                {
                    p=-1;
                    ansy.push(j-b[i].size()+1);
                }
            }
            if(ansx.empty()||ansy.empty())continue;
            int sum=0;
            while(!(ansx.empty()||ansy.empty()))
            {
                if(ansx.front()==ansy.front())
                {
                    sum=1;
                    //cout<<ansx.front()-1<<' '<<ansy.front()+a[i].size()<<endl;
                    for(int j=0;j<ansy.front();j++)
                    {
                        if(x[j]!=y[j])
                        {
                            sum=0;
                            break;
                        }
                    }
                    for(int j=ansy.front()+a[i].size();j<x.size();j++)
                    {
                        if(x[j]!=y[j])
                        {
                            sum=0;
                            break;
                        }
                    }
                    break;
                }
                else if(ansx.front()<ansy.front())
                {
                    ansx.pop();
                }
                else
                {
                    ansy.pop();
                }
            }
            if(sum==1)ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
