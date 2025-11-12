#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
typedef unsigned long long ull;
const int N=2e5;
const int L=5e6;
int n,q,pos1,pos2,cnt[L+5],maxx,f=1;
string s1[N+5],s2[N+5];
vector<int> v[L+5];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        for(int j=0;j<s1[i].size();j++)
        {
            if(s1[i][j]!='a'&&s1[i][j]!='b')
                f=0;
            if(s2[i][j]!='a'&&s2[i][j]!='b')
                f=0;
            if(s1[i][j]=='b')
                pos1=j;
            if(s2[i][j]=='b')
                pos2=j;
        }
        v[abs(pos1-pos2)].push_back(max(pos1,pos2)-1);
        maxx=max(maxx,abs(pos1-pos2));
        //cout<<abs(pos1-pos2)<<endl;
    }
    for(int i=0;i<=maxx;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=1;i<=q;i++)
    {
        s1[i]="",s2[i]="";
        cin>>s1[i]>>s2[i];
        if(f==0||(s1[i].size()!=s2[i].size()))
        {
            cout<<0<<endl;
            continue;
        }
        for(int j=0;j<s1[i].size();j++)
        {
            if(s1[i][j]=='b')
                pos1=j;
            if(s2[i][j]=='b')
                pos2=j;
        }
        int t=abs(pos1-pos2),x=max(pos1,pos2)-1;
        int l=0,r=v[t].size()-1,res=-1;
        //cout<<r<<endl;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(v[t][mid]>x)
                res=mid,r=mid-1;
            else l=mid+1;
        }
        if(res!=-1) printf("%d\n",res);
        else if(v[t][v[t].size()-1]<=x) printf("%d\n",v[t].size());
        else printf("0\n");
    }
    return 0;
}
