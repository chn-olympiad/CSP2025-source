#include<bits/stdc++.h>
using namespace std;
int n,m;
//.......h
//.l
//.
struct str{
    int f;
    int bh;
    int h;
    int l;
};
bool cmp(str x,str y){
    if(x.f>y.f) return 1;
    return 0;
}
int main()
{
    str s[105];
    cin>>n>>m;
    int a=m*n;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    for(int i=1;i<=a;i++)
    {
        cin>>s[i].f;
        s[i].bh=i;
    }
    sort(s+1,s+1+a,cmp);
    int sum=0;
    int smu=0;
    for(int i=1;i<=m;i++)
    {
        smu++;
        if(smu%2-==0)
        {
            for(int j=1;j<=n;j++)
            {
                sum++;
                s[sum].l=i;
                s[sum].h=j;
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                sum++;
                s[sum].l=i;
                s[sum].h=j;
            }
        }
    }
    cout<<s[s[1].bh].h<<" "<<s[s[1].bh].l;
    return 0;
}
