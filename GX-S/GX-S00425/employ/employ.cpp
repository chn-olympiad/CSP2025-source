#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
int n,m;
int a[N],c[N],s[N];
char ss[N];
ll ans;
void sub_1_work()
{
    scanf("%s",ss+1);
    for(int i=1;i<=n;i++)s[i]=ss[i]-'0';
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
        scanf("%d",&c[i]);
    }
    int cnt=0,fold=0;
    while(1)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt<c[a[i]]&&s[i])cnt++;
            else fold++;
        }
        ans+=(cnt>=m);
        if(!next_permutation(a+1,a+1+n))break;
    }
    printf("%lld\n",ans);
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n<=10)sub_1_work();
    else cout<<0<<"\n";
    return 0;
}
