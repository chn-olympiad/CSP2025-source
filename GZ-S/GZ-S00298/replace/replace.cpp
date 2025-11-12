// GZ-S00298 遵义四中 温岳城

#include<bits/stdc++.h>
using namespace std;
// 10 pts
int main()
{
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n,q;cin>>n>>q;
    vector<string> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    while(q--)
    {
        int cnt=0;
        string t1,t2;cin>>t1>>t2;
        string tmp=t1;
        for(int i=0;i<n;i++)
        {
            int pos=t1.find(a[i]);
            if(pos!=string::npos) for(int j=pos;j<(pos+b[i].size());j++) t1[j]=b[i][j-pos];
            if(t1==t2) cnt++;
            t1=tmp;
        }
        cout<<cnt<<'\n';
    }
}
