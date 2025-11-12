//GZ-S00386 毕节东辰实验学校 苏长灵珠
#include<bits/stdc++.h>
using namespace std;
const int N=2*1e7;
long long  n,t,ans;
long long a1[N],a2[N],a3[N],b[N],k2[N],cnt[4];
struct node{
    int m,w;
    int k2;
};
node k1[N];
int cmp(node A,node B)
{
    return A.m>B.m;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;

    while(t--)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
           cnt[i]=0;
        }
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a1[i]>>a2[i]>>a3[i];
            if(a1[i]<=a2[i]&&a2[i]<=a3[i])k1[i].m=a3[i],k1[i].k2=a2[i],k1[i].w=3;
           if(a2[i]<=a1[i]&&a1[i]<=a3[i])k1[i].m=a3[i],k1[i].k2=a1[i],k1[i].w=3;

            if(a2[i]<=a3[i]&&a3[i]<=a1[i])k1[i].m=a1[i],k1[i].k2=a3[i],k1[i].w=1;
            if(a3[i]<=a2[i]&&a2[i]<=a1[i])k1[i].m=a1[i],k1[i].k2=a2[i],k1[i].w=1;

            if(a1[i]<=a3[i]&&a3[i]<=a2[i])k1[i].m=a2[i],k1[i].k2=a3[i],k1[i].w=2;
            if(a3[i]<=a1[i]&&a1[i]<=a2[i])k1[i].m=a2[i],k1[i].k2=a1[i],k1[i].w=2;
          //  cout<<k1[i]<<" "<<k2[i];cout<<endl;
        }
        sort(k1+1,k1+1+n,cmp);
        int mid=n/2;
        for(int i=1;i<=n;i++)
        {
            if((a3[i]==0 &&a1[i]==0))
            {
                if((k1[i].m+k1[i-1].k2)>k1[i-1].m)
                {
                    cnt[k1[i].w]++;
                   ans-=k1[i-1].m,ans+=k1[i-1].k2+k1[i].m;continue;
                }
            }
            if((a2[i]==0&&a3[i]==0))
            {
                if((k1[i].m+k1[i-1].k2)>k1[i-1].m)
                {
                    cnt[k1[i].w]++;
                   ans-=k1[i-1].m,ans+=k1[i-1].k2+k1[i].m;continue;
                }
            }
            if((a1[i]==0&&a2[i]==0))
            {
                if((k1[i].m+k1[i-1].k2)>k1[i-1].m)
                {
                    cnt[k1[i].w]++;
                   ans-=k1[i-1].m,ans+=k1[i-1].k2+k1[i].m;continue;
                }
            }

        if(cnt[k1[i].w]>=mid){continue;}
           else cnt[k1[i].w]++,ans+=k1[i].m;

        }
        cout<<ans<<endl;
    }


    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
2
10 3 8
3 0 0
*/
