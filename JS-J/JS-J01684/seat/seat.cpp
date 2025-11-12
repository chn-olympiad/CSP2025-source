#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;
int a[105];
bool cmp(int a,int b)
{
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
        scanf("%d",&a[i]);
    int rs=a[1];
    sort(a+1,a+n*m+1,cmp);
    int i=1,j=1,cnt=1;
    while(i<=n&&j<=m&&i>=1&&j>=1)
    {
        if(a[cnt]==rs)
        {
            printf("%d %d",j,i);
            return 0;
        }
        if(i==n&&j%2)
            j++;
        else if(i==1&&j%2==0)
            j++;
        else if(j%2)
            i++;
        else
            i--;
        cnt++;
    }
    return 0;
}
