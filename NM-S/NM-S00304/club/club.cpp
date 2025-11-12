#include<bits/stdc++.h>
using namespace std;
int t,n,maxn=0,b[4],maxn1=0,c[100001][4],maxn2=0;
struct node{
    int date,num;
}a[4];
bool cmp(node a,node b)
{
    return a.date>b.date;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int m=n/2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[j].date;
                c[i][j]=a[j].date;
                a[i].num=j;
            }
            sort(a+1,a+4,cmp);
            for(int j=1;j<=3;j++)
            {
                if(b[a[j].num]+1<=m)
                {
                    maxn1+=a[j].date;
                    b[a[j].num]++;
                    break;
                }
            }
        }
        for(int j=1;j<=3;j++)
        {
            b[j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                a[j].date=c[n-i+1][j];
                a[j].num=j;
            }
            sort(a+1,a+4,cmp);
            for(int j=1;j<=3;j++)
            {
                if(b[a[j].num]+1<=m)
                {
                    maxn2+=a[j].date;
                    b[a[j].num]++;
                    //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" ";
                    break;
                }
                //cout<<a[j].date;
            }
            //cout<<endl;
        }
        maxn=max(maxn1,maxn2);
        cout<<maxn2<<"\n";
        maxn1=0;
        maxn2=0;
        maxn=0;
    }
    return 0;
}
