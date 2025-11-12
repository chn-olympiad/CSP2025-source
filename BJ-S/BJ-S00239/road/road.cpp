#include<iostream>
using namespace std;
int main()
{
    long long b=rand();
    while(1)
    {
       char a=rand();
       cout<<a;
       for(long long i=1;i<=a;i++) cout<<' ';
       i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                f(a=="#include<bits/stdc++.h>
using namespace std;
long long a[100010][4],dp[400][400][400],n;
long long florr(long long x,long long y,long long z)
{
    if(x+y+z>n-1) return 0;
    else if(x+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x,y,z+1)+a[x+y+z][3]);
    else if(y+1>n/2) return max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y,z+1)+a[x+y+z][3]);
    else if(z+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x+1,y,z)+a[x+y+z][1]);
    else return max(max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y+1,z)+a[x+y+z][2]),florr(x,y,z+1)+a[x+y+z][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long pp=0;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            pp+=a[i][3];
        }
        if(n<=10) cout<<florr(0,0,0)<<endl;
        else if(pp==0)
        {
            long long h[100010]={0},o=0,q=0,sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(a[i][1],a[i][2]);
                if(a[i][1]>a[i][2]) o++;
            }
            if(o>n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]>a[i][2]) h[++q]=a[i][1]-a[i][2];
                }
            }
            if(o<n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]<a[i][2]) h[++q]=a[i][2]-a[i][1];
                }
            }
            sort(h+1,h+q+1);
            if(o>n/2)
            {
                for(long long i=1;i<=o-n/2;i++) sum-=h[i];
            }
            if(o<n/2)
            {
                for(long long i=1;i<=n/2-o;i++)
                {
                    sum-=h[i];
                }
            }
            cout<<sum<<endl;
        }
        else
        {
            long long sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<sum;
        }
    }
    return 0;
}
") return 0;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    long long b=rand();
    while(1)
    {
       char a=rand();
       cout<<a;
       for(long long i=1;i<=a;i++) cout<<' ';
       i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                f(a=="#include<bits/stdc++.h>
using namespace std;
long long a[100010][4],dp[400][400][400],n;
long long florr(long long x,long long y,long long z)
{
    if(x+y+z>n-1) return 0;
    else if(x+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x,y,z+1)+a[x+y+z][3]);
    else if(y+1>n/2) return max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y,z+1)+a[x+y+z][3]);
    else if(z+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x+1,y,z)+a[x+y+z][1]);
    else return max(max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y+1,z)+a[x+y+z][2]),florr(x,y,z+1)+a[x+y+z][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long pp=0;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            pp+=a[i][3];
        }
        if(n<=10) cout<<florr(0,0,0)<<endl;
        else if(pp==0)
        {
            long long h[100010]={0},o=0,q=0,sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(a[i][1],a[i][2]);
                if(a[i][1]>a[i][2]) o++;
            }
            if(o>n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]>a[i][2]) h[++q]=a[i][1]-a[i][2];
                }
            }
            if(o<n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]<a[i][2]) h[++q]=a[i][2]-a[i][1];
                }
            }
            sort(h+1,h+q+1);
            if(o>n/2)
            {
                for(long long i=1;i<=o-n/2;i++) sum-=h[i];
            }
            if(o<n/2)
            {
                for(long long i=1;i<=n/2-o;i++)
                {
                    sum-=h[i];
                }
            }
            cout<<sum<<endl;
        }
        else
        {
            long long sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<sum;
        }
    }
    return 0;
}
") return 0;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    long long b=rand();
    while(1)
    {
       char a=rand();
       cout<<a;
       for(long long i=1;i<=a;i++) cout<<' ';
       i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                f(a=="#include<bits/stdc++.h>
using namespace std;
long long a[100010][4],dp[400][400][400],n;
long long florr(long long x,long long y,long long z)
{
    if(x+y+z>n-1) return 0;
    else if(x+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x,y,z+1)+a[x+y+z][3]);
    else if(y+1>n/2) return max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y,z+1)+a[x+y+z][3]);
    else if(z+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x+1,y,z)+a[x+y+z][1]);
    else return max(max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y+1,z)+a[x+y+z][2]),florr(x,y,z+1)+a[x+y+z][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long pp=0;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            pp+=a[i][3];
        }
        if(n<=10) cout<<florr(0,0,0)<<endl;
        else if(pp==0)
        {
            long long h[100010]={0},o=0,q=0,sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(a[i][1],a[i][2]);
                if(a[i][1]>a[i][2]) o++;
            }
            if(o>n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]>a[i][2]) h[++q]=a[i][1]-a[i][2];
                }
            }
            if(o<n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]<a[i][2]) h[++q]=a[i][2]-a[i][1];
                }
            }
            sort(h+1,h+q+1);
            if(o>n/2)
            {
                for(long long i=1;i<=o-n/2;i++) sum-=h[i];
            }
            if(o<n/2)
            {
                for(long long i=1;i<=n/2-o;i++)
                {
                    sum-=h[i];
                }
            }
            cout<<sum<<endl;
        }
        else
        {
            long long sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<sum;
        }
    }
    return 0;
}
") return 0;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    long long b=rand();
    while(1)
    {
       char a=rand();
       cout<<a;
       for(long long i=1;i<=a;i++) cout<<' ';
       i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                f(a=="#include<bits/stdc++.h>
using namespace std;
long long a[100010][4],dp[400][400][400],n;
long long florr(long long x,long long y,long long z)
{
    if(x+y+z>n-1) return 0;
    else if(x+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x,y,z+1)+a[x+y+z][3]);
    else if(y+1>n/2) return max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y,z+1)+a[x+y+z][3]);
    else if(z+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x+1,y,z)+a[x+y+z][1]);
    else return max(max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y+1,z)+a[x+y+z][2]),florr(x,y,z+1)+a[x+y+z][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long pp=0;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            pp+=a[i][3];
        }
        if(n<=10) cout<<florr(0,0,0)<<endl;
        else if(pp==0)
        {
            long long h[100010]={0},o=0,q=0,sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(a[i][1],a[i][2]);
                if(a[i][1]>a[i][2]) o++;
            }
            if(o>n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]>a[i][2]) h[++q]=a[i][1]-a[i][2];
                }
            }
            if(o<n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]<a[i][2]) h[++q]=a[i][2]-a[i][1];
                }
            }
            sort(h+1,h+q+1);
            if(o>n/2)
            {
                for(long long i=1;i<=o-n/2;i++) sum-=h[i];
            }
            if(o<n/2)
            {
                for(long long i=1;i<=n/2-o;i++)
                {
                    sum-=h[i];
                }
            }
            cout<<sum<<endl;
        }
        else
        {
            long long sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<sum;
        }
    }
    return 0;
}
") return 0;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    long long b=rand();
    while(1)
    {
       char a=rand();
       cout<<a;
       for(long long i=1;i<=a;i++) cout<<' ';
       i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                f(a=="#include<bits/stdc++.h>
using namespace std;
long long a[100010][4],dp[400][400][400],n;
long long florr(long long x,long long y,long long z)
{
    if(x+y+z>n-1) return 0;
    else if(x+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x,y,z+1)+a[x+y+z][3]);
    else if(y+1>n/2) return max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y,z+1)+a[x+y+z][3]);
    else if(z+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x+1,y,z)+a[x+y+z][1]);
    else return max(max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y+1,z)+a[x+y+z][2]),florr(x,y,z+1)+a[x+y+z][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long pp=0;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            pp+=a[i][3];
        }
        if(n<=10) cout<<florr(0,0,0)<<endl;
        else if(pp==0)
        {
            long long h[100010]={0},o=0,q=0,sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(a[i][1],a[i][2]);
                if(a[i][1]>a[i][2]) o++;
            }
            if(o>n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]>a[i][2]) h[++q]=a[i][1]-a[i][2];
                }
            }
            if(o<n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]<a[i][2]) h[++q]=a[i][2]-a[i][1];
                }
            }
            sort(h+1,h+q+1);
            if(o>n/2)
            {
                for(long long i=1;i<=o-n/2;i++) sum-=h[i];
            }
            if(o<n/2)
            {
                for(long long i=1;i<=n/2-o;i++)
                {
                    sum-=h[i];
                }
            }
            cout<<sum<<endl;
        }
        else
        {
            long long sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<sum;
        }
    }
    return 0;
}
") return 0;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    long long b=rand();
    while(1)
    {
       char a=rand();
       cout<<a;
       for(long long i=1;i<=a;i++) cout<<' ';
       i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                f(a=="#include<bits/stdc++.h>
using namespace std;
long long a[100010][4],dp[400][400][400],n;
long long florr(long long x,long long y,long long z)
{
    if(x+y+z>n-1) return 0;
    else if(x+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x,y,z+1)+a[x+y+z][3]);
    else if(y+1>n/2) return max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y,z+1)+a[x+y+z][3]);
    else if(z+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x+1,y,z)+a[x+y+z][1]);
    else return max(max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y+1,z)+a[x+y+z][2]),florr(x,y,z+1)+a[x+y+z][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long pp=0;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            pp+=a[i][3];
        }
        if(n<=10) cout<<florr(0,0,0)<<endl;
        else if(pp==0)
        {
            long long h[100010]={0},o=0,q=0,sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(a[i][1],a[i][2]);
                if(a[i][1]>a[i][2]) o++;
            }
            if(o>n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]>a[i][2]) h[++q]=a[i][1]-a[i][2];
                }
            }
            if(o<n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]<a[i][2]) h[++q]=a[i][2]-a[i][1];
                }
            }
            sort(h+1,h+q+1);
            if(o>n/2)
            {
                for(long long i=1;i<=o-n/2;i++) sum-=h[i];
            }
            if(o<n/2)
            {
                for(long long i=1;i<=n/2-o;i++)
                {
                    sum-=h[i];
                }
            }
            cout<<sum<<endl;
        }
        else
        {
            long long sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<sum;
        }
    }
    return 0;
}
") return 0;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    long long b=rand();
    while(1)
    {
       char a=rand();
       cout<<a;
       for(long long i=1;i<=a;i++) cout<<' ';
       i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                f(a=="#include<bits/stdc++.h>
using namespace std;
long long a[100010][4],dp[400][400][400],n;
long long florr(long long x,long long y,long long z)
{
    if(x+y+z>n-1) return 0;
    else if(x+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x,y,z+1)+a[x+y+z][3]);
    else if(y+1>n/2) return max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y,z+1)+a[x+y+z][3]);
    else if(z+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x+1,y,z)+a[x+y+z][1]);
    else return max(max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y+1,z)+a[x+y+z][2]),florr(x,y,z+1)+a[x+y+z][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long pp=0;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            pp+=a[i][3];
        }
        if(n<=10) cout<<florr(0,0,0)<<endl;
        else if(pp==0)
        {
            long long h[100010]={0},o=0,q=0,sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(a[i][1],a[i][2]);
                if(a[i][1]>a[i][2]) o++;
            }
            if(o>n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]>a[i][2]) h[++q]=a[i][1]-a[i][2];
                }
            }
            if(o<n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]<a[i][2]) h[++q]=a[i][2]-a[i][1];
                }
            }
            sort(h+1,h+q+1);
            if(o>n/2)
            {
                for(long long i=1;i<=o-n/2;i++) sum-=h[i];
            }
            if(o<n/2)
            {
                for(long long i=1;i<=n/2-o;i++)
                {
                    sum-=h[i];
                }
            }
            cout<<sum<<endl;
        }
        else
        {
            long long sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<sum;
        }
    }
    return 0;
}
") return 0;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    long long b=rand();
    while(1)
    {
       char a=rand();
       cout<<a;
       for(long long i=1;i<=a;i++) cout<<' ';
       i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                f(a=="#include<bits/stdc++.h>
using namespace std;
long long a[100010][4],dp[400][400][400],n;
long long florr(long long x,long long y,long long z)
{
    if(x+y+z>n-1) return 0;
    else if(x+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x,y,z+1)+a[x+y+z][3]);
    else if(y+1>n/2) return max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y,z+1)+a[x+y+z][3]);
    else if(z+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x+1,y,z)+a[x+y+z][1]);
    else return max(max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y+1,z)+a[x+y+z][2]),florr(x,y,z+1)+a[x+y+z][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long pp=0;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            pp+=a[i][3];
        }
        if(n<=10) cout<<florr(0,0,0)<<endl;
        else if(pp==0)
        {
            long long h[100010]={0},o=0,q=0,sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(a[i][1],a[i][2]);
                if(a[i][1]>a[i][2]) o++;
            }
            if(o>n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]>a[i][2]) h[++q]=a[i][1]-a[i][2];
                }
            }
            if(o<n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]<a[i][2]) h[++q]=a[i][2]-a[i][1];
                }
            }
            sort(h+1,h+q+1);
            if(o>n/2)
            {
                for(long long i=1;i<=o-n/2;i++) sum-=h[i];
            }
            if(o<n/2)
            {
                for(long long i=1;i<=n/2-o;i++)
                {
                    sum-=h[i];
                }
            }
            cout<<sum<<endl;
        }
        else
        {
            long long sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<sum;
        }
    }
    return 0;
}
") return 0;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    long long b=rand();
    while(1)
    {
       char a=rand();
       cout<<a;
       for(long long i=1;i<=a;i++) cout<<' ';
       i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                f(a=="#include<bits/stdc++.h>
using namespace std;
long long a[100010][4],dp[400][400][400],n;
long long florr(long long x,long long y,long long z)
{
    if(x+y+z>n-1) return 0;
    else if(x+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x,y,z+1)+a[x+y+z][3]);
    else if(y+1>n/2) return max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y,z+1)+a[x+y+z][3]);
    else if(z+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x+1,y,z)+a[x+y+z][1]);
    else return max(max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y+1,z)+a[x+y+z][2]),florr(x,y,z+1)+a[x+y+z][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long pp=0;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            pp+=a[i][3];
        }
        if(n<=10) cout<<florr(0,0,0)<<endl;
        else if(pp==0)
        {
            long long h[100010]={0},o=0,q=0,sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(a[i][1],a[i][2]);
                if(a[i][1]>a[i][2]) o++;
            }
            if(o>n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]>a[i][2]) h[++q]=a[i][1]-a[i][2];
                }
            }
            if(o<n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]<a[i][2]) h[++q]=a[i][2]-a[i][1];
                }
            }
            sort(h+1,h+q+1);
            if(o>n/2)
            {
                for(long long i=1;i<=o-n/2;i++) sum-=h[i];
            }
            if(o<n/2)
            {
                for(long long i=1;i<=n/2-o;i++)
                {
                    sum-=h[i];
                }
            }
            cout<<sum<<endl;
        }
        else
        {
            long long sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<sum;
        }
    }
    return 0;
}
") return 0;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    long long b=rand();
    while(1)
    {
       char a=rand();
       cout<<a;
       for(long long i=1;i<=a;i++) cout<<' ';
       i                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                f(a=="#include<bits/stdc++.h>
using namespace std;
long long a[100010][4],dp[400][400][400],n;
long long florr(long long x,long long y,long long z)
{
    if(x+y+z>n-1) return 0;
    else if(x+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x,y,z+1)+a[x+y+z][3]);
    else if(y+1>n/2) return max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y,z+1)+a[x+y+z][3]);
    else if(z+1>n/2) return max(florr(x,y+1,z)+a[x+y+z][2],florr(x+1,y,z)+a[x+y+z][1]);
    else return max(max(florr(x+1,y,z)+a[x+y+z][1],florr(x,y+1,z)+a[x+y+z][2]),florr(x,y,z+1)+a[x+y+z][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long pp=0;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            pp+=a[i][3];
        }
        if(n<=10) cout<<florr(0,0,0)<<endl;
        else if(pp==0)
        {
            long long h[100010]={0},o=0,q=0,sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(a[i][1],a[i][2]);
                if(a[i][1]>a[i][2]) o++;
            }
            if(o>n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]>a[i][2]) h[++q]=a[i][1]-a[i][2];
                }
            }
            if(o<n/2)
            {
                for(long long i=0;i<n;i++)
                {
                    if(a[i][1]<a[i][2]) h[++q]=a[i][2]-a[i][1];
                }
            }
            sort(h+1,h+q+1);
            if(o>n/2)
            {
                for(long long i=1;i<=o-n/2;i++) sum-=h[i];
            }
            if(o<n/2)
            {
                for(long long i=1;i<=n/2-o;i++)
                {
                    sum-=h[i];
                }
            }
            cout<<sum<<endl;
        }
        else
        {
            long long sum=0;
            for(long long i=0;i<n;i++)
            {
                sum+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
            cout<<sum;
        }
    }
    return 0;
}
") return 0;
    }
    return 0;
}
