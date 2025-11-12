#include<bits/stdc++.h>
using namespace std;
const int Maxn=510;
int n,m;
int s[Maxn];
int c[Maxn];

int tmp[Maxn];
bool check()
{
    int cnt=0;
    int lst=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==0)
        {
            lst++;
            continue;
        }
        if(lst>=c[tmp[i]])
        {
            lst++;
            continue;
        }
        cnt++;
    }
    return cnt>=m;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        char ch;
        cin>>ch;
        s[i]=ch-'0';
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }

    for(int i=1;i<=n;i++)
    {
        tmp[i]=i;
    }
    int ans=0;
    do{
        ans+=check();
    }while(next_permutation(tmp+1,tmp+1+n));
    printf("%d\n",ans);
    return 0;
}
