#include<bits/stdc++.h>
using namespace std;
vector<int> a,x;
vector<pair<int,int>> c;
int f[100][100];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k;
    cin>>n>>k;
    a.push_back(0);
    x.push_back(0);
    int cnt0=0;
	for(int i=1;i<=n;i++)
    {
        int d;
        scanf("%d",&d);
        a.push_back(d);
        x.push_back((d^x[i-1]));
        for(int j=1;j<=i;j++)
        {
            if((x[i]^x[j-1])==k)
            {
                c.push_back({j,i});


            }

        }
    }
    bool flag2=false,flag0=false;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>1) flag2=true;
        if(a[i]==0) flag0=true,cnt0++;

    }

    int ans=0;
    if(k==0)
    {

        cout<<n;
        return 0;
    }
    if(!flag2&&!flag0)
    {

        if(k==1)
        {

            cout<<n/3;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    if(!flag2&&flag0)
    {
        if(k==1)
            cout<<(n-cnt0)/3;
        else    cout<<0;
        return 0;

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j+i<=n;j++)
        {
            if((x[i+j]^x[i-1])==k)
            {
                ans++;
                i=j+1;
                break;
            }

        }
    }
    cout<<ans;
    return 0;
}
