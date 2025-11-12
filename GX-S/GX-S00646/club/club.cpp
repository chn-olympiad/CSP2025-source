    #include<bits/stdc++.h>
    using namespace std;
    long long n,t,a[20005],b[20005],c[20005],ttt=0,tt=0;
    int main()
    {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++)
    {
    cin>>t;
    tt=0;
    for(int j=1;j<=t;j++)
    {
    cin>>a[j]>>b[j]>>c[j];
    for(int x=1;x<=3;x++)
    {
     if(a[j]>=ttt)ttt=a[j];
    if(b[j]>=ttt)ttt=b[j];
    if(c[j]>=ttt)ttt=c[j];
    }
    tt+=ttt;
    ttt=0;
    }
   cout<<tt;

    }

    return 0;
    }
