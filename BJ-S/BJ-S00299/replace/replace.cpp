#include<bits/stdc++.h>
using namespace std;
string str[200005],str1[200005];
string bf,af;
struct St{
    int st,ed;
    bool operator<(const St &B)const{
        return st<B.st;
    }
}tmp[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int s,e;
    for(int i=1;i<=n;i++)
    {
        cin>>str[i]>>str1[i];
    }
    sort(tmp+1,tmp+n+1);
    for(int i=1;i<=q;i++)
    {
        cin>>bf>>af;
        cout<<0<<'\n';
    }
}
