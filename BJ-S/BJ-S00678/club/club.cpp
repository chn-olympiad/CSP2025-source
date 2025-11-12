#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int t;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n,a1[100001],a2[100001],a3[100001];
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a1[i]>>a2[i]>>a3[i];
        sort(a1+1,a1+n+1);
        sort(a2+1,a2+n+1);
        sort(a3+1,a3+n+1);
        int sum=0,b1=1,b2=1,b3=1;
        sum=a1[1]+a2[1]+a3[1];
        for(int i=2;i<=n;++i)
        {
            sum+=max(a1[i],max(a2[i],a3[i]));
            if(a1[i]==max(a1[i],max(a2[i],a3[i])))
                b1++;
            else if(a2[i]==max(a1[i],max(a2[i],a3[i])))
                b2++;
            else if(a3[i]==max(a1[i],max(a2[i],a3[i])))
                b3++;
            if(b1+b2-n/2<b3)
            {
                b3--;
                sum-=a3[i];
                sum+=max(a1[i],a2[i]);
                if(a1[i]==max(a1[i],a2[i]))
                    b1++;
                else
                    b2++;
            }
            if(b1+b3-n/2<b2)
            {
                b2--;
                sum-=a2[i];
                sum+=max(a1[i],a3[i]);
                if(a1[i]==max(a1[i],a3[i]))
                    b1++;
                else
                    b3++;
            }
            if(b3+b2-n/2<b1)
            {
                b1--;
                sum-=a1[i];
                sum+=max(a3[i],a2[i]);
                if(a2[i]==max(a3[i],a2[i]))
                    b2++;
                else
                    b3++;
            }
        }
        cout<<sum<<endl;
        sum=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
