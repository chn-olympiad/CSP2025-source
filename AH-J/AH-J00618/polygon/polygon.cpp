#include <bits/stdc++.h>

using namespace std;

const int mod=998244353;
int n,m,s;
int a[300101];
vector<int> c;
bool check(vector<int> a,int k)
{
    if(a.back()==1)return true;
    int t=-1,sum=0;
    while((++t)<k-1)sum+=a[t];
    if(sum>a.back())return true;
    else if(sum<=a.back())return false;
}
void fdw(int f,int k)
{
    if(f>=3&&check(c,f)){s++;s%=mod;}
    if(f>=n)return;
    for(int i=1;i+k<=n;i++)
    {
        c.push_back(a[i+k]);
        fdw(f+1,k+i);
        c.pop_back();
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    c.clear();
    cin >> n;
    for(int k=1; k<=n; k++)
    {
        cin >> a[k];
    }
    sort(a+1,a+n+1);
    fdw(0,0);
    cout << (s%mod);
    return 0;
}
