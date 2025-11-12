#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int s1,int s2)
{
    return s1>s2;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<n*m;i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
    int r=v[0];
    sort(v.begin(),v.end(),cmp);
    int t=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=(i%2==0?j=m:j=1);(i%2==0?j>0:j<=m);(i%2==0?j--:j++))
        {
            if(v[t]==r)
            {
                cout<<i<<' '<<j;
                return 0;
            }
            t++;
        }
    }
}
