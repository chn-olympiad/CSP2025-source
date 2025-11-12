// GZ-S00298 遵义四中 温岳城

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
// 直接全 WA 好吧，老实了
int main()
{
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int half=n/2;
        vector<vector<int> > a(n,vector<int>(3));
        for(int i=0;i<n;i++) for(int j=0;j<3;j++) cin>>a[i][j];
        if(n==2)
        {
            int tmp1=max(max(a[0][0],a[0][1]),a[0][2]),tmp2=max(max(a[1][0],a[1][1]),a[1][2]);
            cout<<tmp1+tmp2<<'\n';
            continue;
        }
        vector<vector<int> > b(n,vector<int>(4,0));
        int maxn=INT_MIN,sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<4;j++)
                b[i][j]=a[i][j-1]-b[i][j-1],maxn=max(maxn,b[i][j]);
            sum+=maxn,maxn=INT_MIN;
        }
        cout<<sum<<'\n';
    }
}
