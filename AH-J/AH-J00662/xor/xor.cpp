#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    bool oj1=true,oj2=true;
    cin >> n >> k;
    vector<ll >a(n);
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
        if(a[i]!=1)oj1=false;
        if(a[i]!=0&&a[i]!=1)oj2=false;
    }
    if(oj1==true)
    {
        if(k==1)cout << n;
        else if(k==0)cout <<n/2;
    }
    else if(oj2==true)
    {
        ll sum=0;
        if(k==0)
        {
            for(int i=0;i<n;++i)
            {
                if(a[i]==0)++sum;
                else if(a[i]==1&&a[i+1]==1)
                {
                    ++sum;
                    ++i;
                }
            }
        }
        else
        {
            for(int i=0;i<n;++i)
            {
                if(a[i]==1)++sum;
            }
        }
        cout << sum;
    }
    else
    {
        ll ans=0;
        for(int i=0;i<n;++i)
        {
            bool oj=false;
            if(a[i]==k)
            {
                ++ans;
                continue;
            }
            int j=i;
            if(i!=n-1){
                int j=i+1;
                for(;j<n;++j)
                {
                    ll sum=a[i];
                    for(int o=i+1;o<=j;++o)
                        sum=sum^a[o];
                    if(sum==k)
                    {
                        ++ans;
                        oj=true;
                        break;
                    }
                }
            }
            if(oj==true)i=j;
        }
        cout << ans;
    }
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
