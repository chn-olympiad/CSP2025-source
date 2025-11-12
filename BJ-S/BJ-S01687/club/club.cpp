#include<bits/stdc++.h>
using namespace std;
long long A[100010];
long long B[100010];
long long C[100010];

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long T;
    cin>> T;
    while(T--)
    {
        long long cnta=0;
        long long cntb=0;
        long long cntc=0;
        long long ans=0;
        long long n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            long long a,b,c;
            cin>> a>>b >> c;
            if(a==b || b==c ||a==c)
            {
                if(a==b)
                {
                    ans+=a;
                }
                if(b==c)
                {
                    ans+=b;
                }
                if(a==c)
                {
                    ans+=c;
                }
                continue;
            }
            if(a>b && a>c)
            {
                ans+=a;
                cnta++;
                A[cnta]=a-max(b,c);
            }
            if(b>a &&b>c)
            {
                ans+=b;
                cntb++;
                B[cntb]=b-max(a,c);
            }
            if(c>a && c>b)
            {
                ans+=c;
                cntc++;
                C[cntc]=c-max(a,b);
            }
        }
        if(cnta>n/2)
        {
            sort(A+1,A+cnta+1);
            int i=1;
            while(cnta>n/2)
            {
                cnta--;
                ans-=A[i];
                i++;
            }
        }
        if(cntb>n/2)
        {
            sort(B+1,B+cntb+1);
            int i=1;
            while(cntb>n/2)
            {
                cntb--;
                ans-=B[i];
                i++;
            }
        }
        if(cntc>n/2)
        {
            sort(C+1,C+cntc+1);
            int i=1;
            while(cntc>n/2)
            {
                cntc--;
                ans-=C[i];
                i++;
            }
        }
        cout<<ans <<endl;
    }
    return 0;
}