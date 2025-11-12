#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxx,maxa[114514],maxb[114514],maxc[114514],cnta,cntb,cntc,sum1,sum2,sum3;
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,a,b,c;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
           cin>>a>>b>>c;
           maxx+=max({a,b,c});
	   }
        cout<<maxx<<endl;
        maxx=0;
}
    return 0;
}
