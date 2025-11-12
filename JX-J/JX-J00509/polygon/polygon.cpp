#include<bits/stdc++.h>
using namespace std;
int a[5010]={};
int ans=0;
void s(int d,int b)
{
    int dd=d-1,ddd=b;
    while(dd>b-1)
    {
        ans+=dd;
        dd--;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.ans","w",stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n; i>2; --i)
    {
        for(int j=i-1; j>1; --j)
        {
            for(int k=j-1; k>0; --k)
            {
                if(a[i]+a[j]+a[k]>a[i]*2) s(j,k);
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
