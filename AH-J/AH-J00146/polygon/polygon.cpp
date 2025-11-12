#include<bits/stdc++.h>
using namespace std;
vector<long long> num;
long long cnt;
long long n;

long long dfs(int k,long long zong,int t)
{
    if(k==0)
        return zong;
    long long nm;
    for(int i=t;i<num.size();i++)
    {
        nm=zong+num[i];
        dfs(k-1,nm,i+1);
        if(k==1 && nm>num[i]*2)
            cnt++;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        num.push_back(x);
    }
    sort(num.begin(),num.end());
    for(int i=3;i<=n;i++)
    {
        dfs(i,0,0);
    }
    cout<<cnt%998244353;
    return 0;
}
