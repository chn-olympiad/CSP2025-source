
#include<bits/stdc++.h>
using namespace std;
int a[5001],b[5001];
vector<int> c;
long long cnt=0;
int n;
void p(int bian, int dep,int start,int sum,int maxn)
{
    if(dep>bian-1)
    {
        if(2*maxn<sum)
            cnt++;
        cnt%=998244353;
        return ;
    }
    for(int i=start;i<=n;i++)
    {

        p(bian,dep+1,i+1,sum+i,i);

    }

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);


    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    sort(a+1,a+n+1);

    for(int i=3;i<=n;i++)
        p(i,0,1,0,-1);



    cout<<cnt;
    return 0;
}
