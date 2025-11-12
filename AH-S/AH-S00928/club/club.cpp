#include<bits/stdc++.h>
using namespace std;
int n,aa[100005][4],maxn;
void search(int s,int a,int b,int c)
{
    if(a>n/2||b>n/2||c>n/2) return;
    maxn=max(s,maxn);
    for(int i=1;i<=3;i++)
    {
        if(i==1) search(s+aa[a+b+c][1],a+1,b,c);
        if(i==2) search(s+aa[a+b+c][2],a,b+1,c);
        if(i==3) search(s+aa[a+b+c][3],a,b,c+1);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
                cin>>aa[i][j];
        }
        maxn=0;
        search(0,0,0,0);
        cout<<maxn<<endl;
    }
    return 0;
}
