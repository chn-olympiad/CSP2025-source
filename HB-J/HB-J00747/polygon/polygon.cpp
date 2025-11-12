#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int tot=0;
/*struct tree{
    int f[25000010];
    int lowbit(int x){return x&(-x);}
    void put(int x,int a){for (;x>0;x-=lowbit(x)) (f[x]+=a)%=mod;}
    int get(int x){return (x>tot?0:f[x]+get(x+lowbit(x)));}
}t;*/
int read()
{
    char ch=getchar();
    int x=0,f=1;
    while (!isdigit(ch))
    {
        if (ch=='-') f=-f;
        ch=getchar();
    }
    while (isdigit(ch))
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int t[25000010];
int a[5010];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    tot=a[1]+a[2];
    t[a[1]]++,t[a[2]]++,t[a[1]+a[2]]++;
    int ans=0;
    for (int i=3;i<=n;i++)
    {
		tot+=a[i];
		for (int j=a[i]+1;j<=tot;j++) (ans+=t[j])%=mod;
		for (int j=tot;j>=1;j--) (t[j+a[i]]+=t[j])%=mod;
		t[a[i]]++;
    }
    cout<<ans;
}
