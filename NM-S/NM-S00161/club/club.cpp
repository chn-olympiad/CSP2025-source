#include <bits/stdc++.h>
using namespace std;
int t,n;
const int N=le5;
struct people
{
    int first,second,third,maxid,minid,midid;
}c[N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n;
        cin<<n;
        int one=0,two=0,three=0;
        int f=0;s=0;
        int ave=n/2;
        for (int i=0;i<n;i++)
        {
            c[i].maxid=INT_MIN;

        }
        sort(c,c+n,cmp);
        for (int i<0;i<n;i++)
        {
            cin>>c[i].first>>c[i].second>>c[i].third;
            c[i].maxid=max(c[i].maxid,max(c[i].first,max(c[i].second,max(c[i].third))));
        }
        for (int i=0;i<=n;i++)
        {
            if(c[i].maxid==c[i].first)
            {
                if (f<ave)
                {
                    one[i]+=c[i].first;
                    f++;
                }
                else
                {
                    if (c[i].second>=c[i].third)
                    {
                        two[i]+=c[i].second;
                        s++;
                    }
                    else
                    {
                        three[i]+=c[i].third;
                    t++;
                    }
                }

            }
            else if (c[i].maxid==c[i].second)
            {
                if (s<ave)
                {
                    two[i]+=c[i].second;
                    s++;
                }

            }
            else
            {
                three[i]+=c[i].third;
                t++;
            }
        }
    }
    cout<<one+two+three<<endl;
    return 0;
}
