#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin >> n >> k;
    vector<int> c(n+1);
    vector<int> s(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
        s[i]=s[i-1]^c[i];
    }
    if(k==0){
        cout << n/2;
        return 0;
    }
    vector<pair<long long,long long>> v;
    bool All=false;
    for(int l=1;l<=n;l++)
    {
        bool flag=true;
        for(int r=l;r<=n;r++)
        {
            int t=s[r]^s[l-1];
            if(t==k)
            {
                if(!flag)All=true;
                v.push_back({l,r});
                flag=false;
            }
        }
    }
    if(!All)cout << v.size();
    else cout << v.size()/2;
    return 0;
}
