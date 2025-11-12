#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int >a(n);
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }
    long long ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int sum=0,maxi=-1;
            for(int k=i;k<=j;++k)
            {
                maxi=max(maxi,a[k]);
                sum+=a[k];
            }
            if(sum>maxi*2)
            {
                ans++;
                cout << i <<' '<< j << endl;
            }
        }
        if(ans>=998244353)ans-=998244353;
    }
    cout << ans;
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
