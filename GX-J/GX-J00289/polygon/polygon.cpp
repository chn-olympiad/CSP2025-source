#include<bits/stdc++.h>
using namespace std;
int p[100001];
int n;
bool cmp(int x,int y)
{
    return x>y;
}
int mugun()
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    sort(p,p+n,cmp);

    return 0;
}
