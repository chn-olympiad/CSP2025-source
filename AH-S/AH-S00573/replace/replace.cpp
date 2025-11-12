#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> P;
vector<int> g[200055];
map<P,int> mp;
int n,q,cnt11;
string a[200055],b[200055],s1,s2;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        string s1=a[i],s2=b[i],s3="",s4="";
        int x=s1.size();
        int first=0,last=0;
        for(int i=0;i<x;i++)
            if(s1[i]!=s2[i])
            {
                first=i;
                break;
            }
        for(int i=x-1;i>=0;i--)
            if(s1[i]!=s2[i])
            {
                last=i;
                break;
            }
        s3=s1.substr(first,last-first+1);
        s4=s2.substr(first,last-first+1);
        P p=make_pair(s3,s4);
        if(mp[p]==0)
        {
            cnt11++;
            mp[p]=cnt11;
        }
        g[mp[p]].push_back(i);
        //P p=make_pair(a[i],b[i]);
        //mp[p]++;
    }
    while(q--)//1citihuan
    {
        cin>>s1>>s2;
        int x=s1.size(),y=s2.size();
        if(x!=y)
        {
            cout<<"0\n";
            continue;
        }
        string s3="",s4="";
        int first=0,last=0;
        for(int i=0;i<x;i++)
            if(s1[i]!=s2[i])
            {
                first=i;
                break;
            }
        for(int i=x-1;i>=0;i--)
            if(s1[i]!=s2[i])
            {
                last=i;
                break;
            }
        s3=s1.substr(first,last-first+1);
        s4=s2.substr(first,last-first+1);
        /*
        for(int i=first;i<=last;i++)
        {
            s3=s3+s1[i];
            s4=s4+s2[i];
        }*/
        //找出最小单元
        int cnt1=0;
        int xxx=mp[P(s3,s4)];
        for(int i=0;i<g[xxx].size();i++)
        {
            int j=g[xxx][i];
            int xx=s1.find(a[j]);
            if(xx!=-1)
                cnt1++;
        }
        printf("%d\n",cnt1);
    }
    return 0;
}
