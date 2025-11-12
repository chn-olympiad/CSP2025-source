#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,vector<string> >mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    while(n--)
    {
        string x,y;
        cin>>x>>y;
        mp[x].push_back(y);
    }
    while(q--)
    {
        string x,y,s="";
        cin>>x>>y;
        int sum=0;
        for(int i=0;i<x.size();i++)
        {

            for(int j=1;i+j-1<x.size();j++)
            {
                string str=x.substr(i,j);
                for(int k=0;k<mp[str].size();k++)
                {
                    if(s+mp[str][k]+x.substr(i+j,n-i-j+1)==y) sum++;
                }
            }
            s+=x[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
