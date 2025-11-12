#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
const int N=1e5+5;
int a[N];
bool cmp(int a,int b)
{
    return a>b;
}
int f(int a,int b)
{
    if(a%b>0)
    {
        return a/b+1;
    }
    else return a/b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
    }
    int mark=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    int cnt=0;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==mark)
        {
            cnt=i;
            break;
        }
    }
    //printf("%d %d\n",mark,cnt);
    printf("%d ",f(cnt,n));
    if(f(cnt,n)%2==0)
    {
        printf("%d",n+1-(cnt%n));
        return 0;
    }
    else{
        if(cnt%n==0)printf("%d",n);
        else printf("%d",cnt%n);
    }
    return 0;
}
