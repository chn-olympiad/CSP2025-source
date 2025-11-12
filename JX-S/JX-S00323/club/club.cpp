#include<bits/stdc++.h>
using namespace std;
       int a[101010]={0};
       int b[101010];
       int c[101010];
        long long ans=-1;
        int n;
    void dfs(int h,int aa,int bb,int cc,long long zh)
    {
        if(h>n)
        {
            ans=max(zh,ans);
            return;
        }
        for(int i=1;i<=3;i++)
        {
            if(i==1)
            {
                if(aa<n/2)
                    dfs(h+1,aa+1,bb,cc,zh+a[h]);
            }
               if(i==2)
            {
                if(bb<n/2)
                    dfs(h+1,aa,bb+1,cc,zh+b[h]);
            }
               if(i==3)
            {
                if(cc<n/2)
                    dfs(h+1,aa,bb,cc+1,zh+c[h]);
            }
        }
        return;
    }
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
   int t;
   cin>>t;
   for(;t>0;t--)
   {
       cin>>n;
        ans=-1;
       int ma1,ma2,ma3;
       ma1=ma2=ma3=-1;
       for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        ma1=max(a[i],ma1);
        ma2=max(b[i],ma2);
        ma3=max(c[i],ma3);

       }
        if(n<=10)
        {
            dfs(1,0,0,0,0);
            cout<<ans<<endl;
        }
       else
       {
            if(ma2==0&&ma3==0)
            {
                sort(a+1,a+1+n);
                int an=0;
                for(int i=n;i>n/2;i--)
                    an+=a[i];
                cout<<an<<endl;
            }
       }
   }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
