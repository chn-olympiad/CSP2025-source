#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
struct node
{
    string s1,s2;
}a[200005];
map<pair<int,int>,int>mp;
pair<int,int>b[200005];
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;cin>>n>>q;
    int ans=0;
    string s1,s2;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        mp[make_pair(s1.find("ab"),s2.find("ba"))]++;
        mp[make_pair(s1.find("ba"),s2.find("ab"))]++;
    }
    string s3,s4;
    while(q--)
    {
        ans=0;
        cin>>s3>>s4;
        int idx1=s3.find("ab"),idx2=s4.find("ba");
        if(mp.find(make_pair(idx1,idx2))!=mp.end())ans+=mp[make_pair(idx1,idx2)];
        if(mp.find(make_pair(s3.find("ba"),s4.find("ab")))!=mp.end())ans+=mp[make_pair(s3.find("ba"),s4.find("ab"))];
        cout<<ans<<endl;
    }

}
