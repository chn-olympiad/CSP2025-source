#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n;
ll s[5005],a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool f=1;
    long long s1=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s1*=i;s1%=mod;
        if(a[i]!=1) f=0;
    }
    if(f==1)
    {
        int ans=0;
        for(int i=n;i>=3;i--)
        {
            long long s2=1,s3=1;
            for(int j=1;j<=i;j++) s2*=j,s2%=mod;
            for(int j=1;j<=n-i;j++) s3*=j,s3%=mod;
            int add=s1/s2/s3;
            add=add%mod;
            ans+=add;ans=ans%mod;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    if(n==3)
    {
        int ans=0;
        for(int i=1;i<=7;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=2;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=2;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }else if(n==4)
    {
        int ans=0;
        for(int i=1;i<=15;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=3;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=3;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }else if(n==5)
    {
        int ans=0;
        for(int i=1;i<=31;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=4;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=4;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }else if(n==6)
    {
        int ans=0;
        for(int i=1;i<=63;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=5;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=5;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }else if(n==7)
    {
        int ans=0;
        for(int i=1;i<=127;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=6;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=6;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }else if(n==8)
    {
        int ans=0;
        for(int i=1;i<=255;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=7;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=7;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }else if(n==9)
    {
        int ans=0;
        for(int i=1;i<=511;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=8;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=8;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }
    else if(n==10)
    {
        int ans=0;
        for(int i=1;i<=1023;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=9;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=9;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }
    else if(n==11)
    {
        int ans=0;
        for(int i=1;i<=2047;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=10;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=10;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }else if(n==12)
    {
        int ans=0;
        for(int i=1;i<=4095;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=11;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=11;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }
    else if(n==13)
    {
        int ans=0;
        for(int i=1;i<=8191;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=13;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=13;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }
    else if(n==14)
    {
        int ans=0;
        for(int i=1;i<=16383;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=13;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=13;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }else if(n==15)
    {
        int ans=0;
        for(int i=1;i<=32767;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=14;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=14;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }
    else if(n==16)
    {
        int ans=0;
        for(int i=1;i<=65535;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=15;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=15;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }
    else if(n==17)
    {
        int ans=0;
        for(int i=1;i<=131071;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=16;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=16;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }
    else if(n==18)
    {
        int ans=0;
        for(int i=1;i<=262143;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=17;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=17;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }
    else if(n==19)
    {
        int ans=0;
        for(int i=1;i<=524287;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=18;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=18;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }else if(n==20)
    {
        int ans=0;
        for(int i=1;i<=1048575;i++)
        {
            int sum=0,mx=-1;
            for(int j=0;j<=19;j++) if(i&(1<<j)) sum+=a[j+1];
            for(int j=19;j>=0;j--) if(i&(1<<j)){mx=a[j+1];break;}
            if(sum>2*mx) ans++;
            ans=ans%mod;
        }
        cout<<ans;
    }
    return 0;
}
