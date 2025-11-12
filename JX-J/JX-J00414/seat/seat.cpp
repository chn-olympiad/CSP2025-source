#include<bits/stdc++.h>
using namespace std;
int s[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&s[i]);
    }
    int sco=s[1];
    sort(s+1,s+1+n*m,cmp);
    int cnt=1;
    while(s[cnt]!=sco)
        cnt++;
    int c,r;
    r=cnt/n+1-(cnt%n==0);
    if(r%2)
    {
        c=cnt-(r-1)*n;
    }
    else{
        c=abs(r*n-cnt)+1;
    }
    printf("%d %d\n",r,c);
    return 0;
}
