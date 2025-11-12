#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;int t[N][10];
int cnt=0;

bool cmp(int x, int y)
{
    return t[x][0]<t[y][0];
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        vector<int> a, b, c;
        for(int i=1;i<=n;i++)
        {
            cin>>t[i][1]>>t[i][2]>>t[i][3];
            int maxn=max(t[i][1], max(t[i][2], t[i][3]));
            if(t[i][1]==maxn)a.push_back(i), t[i][0]=maxn-max(t[i][2], t[i][3]);
            else if(t[i][2]==maxn)b.push_back(i), t[i][0]=maxn-max(t[i][1], t[i][3]);
            else c.push_back(i), t[i][0]=maxn-max(t[i][1], t[i][2]);
            cnt+=maxn;
        }
        int k=n/2;
        if(a.size()>k)
        {
            sort(a.begin(), a.end(), cmp);
            for(int j=0;j<a.size()-k;j++)cnt-=t[a[j]][0];
        }
        if(b.size()>k)
        {
            sort(b.begin(), b.end(), cmp);
            for(int j=0;j<b.size()-k;j++)cnt-=t[b[j]][0];
        }
        if(c.size()>k)
        {
            sort(c.begin(), c.end(), cmp);
            for(int j=0;j<c.size()-k;j++)cnt-=t[c[j]][0];
        }
        cout<<cnt<<endl;
        cnt=0;
    }
    return 0;
}
