#include <bits/stdc++.h>
#define For(e,e1,e2) for(int e=(e1);e<=(e2);e++)
#define For_(e,e1,e2) for(int e=(e1);e<(e2);e++)
#define Rof(e,e1,e2) for(int e=(e2);e>=(e1);e--)
#define Rof_(e,e1,e2) for(int e=(e2);e>(e1);e--)
#define LL long long
#define ULL unsigned long long
#define DB double
#define cint const int
#define cLL const long long
#define vct vector
#define pb push_back
#define sz(ev) ((int)ev.size())
#define ft first
#define sc second
#define exc(e) if(e) continue
#define stop(e) if(e) break
#define ret(e) if(e) return 
using namespace std;

void main_init()
{

}
cint N=1.02e5;
int n;
array <LL,3> a[N];
LL c[N];
void main_solve()
{
    scanf("%d",&n);
    array <int,3> cnt={0,0,0};
    For(i,1,n)
    {
        For_(k,0,3) scanf("%lld",&a[i][k]);
        if(a[i][0]>max(a[i][1],a[i][2])) cnt[0]++;
        else if(a[i][1]>a[i][2]) cnt[1]++;
        else cnt[2]++;
    }
    int k=((cnt[0]>max(cnt[1],cnt[2]))?0:((cnt[1]>cnt[2])?1:2));
    if(k)
    {
        swap(cnt[0],cnt[k]);
        For(i,1,n) swap(a[i][0],a[i][k]);
    }
    LL sum=0ll;
    if(cnt[0]<=(n>>1))
    {
        For(i,1,n) sum+=max(a[i][0],max(a[i][1],a[i][2]));
        printf("%lld\n",sum);
        return ;
    }
    For(i,1,n)
    {
        LL t=max(a[i][1],a[i][2]);
        sum+=t;
        c[i]=a[i][0]-t;
    }
    sort(c+1,c+n+1);
    For(i,(n>>1)+1,n) sum+=c[i];
    printf("%lld\n",sum);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    main_init();
    int _; scanf("%d",&_); while(_--)
        main_solve();
    return 0;
}