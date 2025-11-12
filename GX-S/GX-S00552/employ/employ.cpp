#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
typedef long long ll;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<48||ch>57){if(ch=='-')f=-1;ch=getchar();}
    while(48<=ch&&ch<=57){x=(x*10)+(ch^48);ch=getchar();}
    return x*f;
}

const int N=1e3+10;

const ll mod=998244353;

int n,m;

char S[N];

ll C[N],A[N];

ll check()
{
    ll rejected=0;

    for(int i=1;i<=n;i++)
    {
        if(S[i]=='0'||rejected>=C[A[i]])
            rejected++;
    }

    return n-rejected;
}

void solve()
{
    for(int i=1;i<=n;i++)
        A[i]=i;

    ll ans=0;

    do{

        if(check()>=m)
            ++ans;

    }while(std::next_permutation(A+1,A+1+n));

    printf("%lld\n",(ans%mod));
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    n=read(),m=read();

    scanf("%s",S+1);

    for(int i=1;i<=n;i++)
        C[i]=read();

    solve();

    return 0;
}

