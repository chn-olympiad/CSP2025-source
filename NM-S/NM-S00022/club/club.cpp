# include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
typedef long long ll;
ll t,n,sum,maxn;
struct node
{
    ll sum,num;
};
node a[N],b[N],c[N];

bool cmp(node a,node b)
{
    return a.sum>b.sum;
}

int main()
{
    freopen("club.in","w",stdin);
    freopen("club.out","r",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum=0;
        maxn=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i].sum >> b[i].sum >> c[i].sum;
            a[i].num=i;
            b[i].num=i;
            c[i].num=i;
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        sort(c+1,c+n+1,cmp);
        for(int i=1;i<=n/2;i++)
        {
            sum=a[i].sum;
            for(int j=1;j<=n/2;j++)
            {
                if(j!=i)
                    sum+=a[j].sum;
                if(b[j].num!=a[i].num)
                    sum+=b[j].sum;
                if(c[j].num!=a[i].num)
                    sum+=c[j].sum;
                if(c[j].num==b[j].num)
                    sum=sum-min(b[j].num,c[j].num);
            }
            maxn=max(maxn,sum);
            sum=b[i].sum;
            for(int j=1;j<=n/2;j++)
            {
                if(j!=i)
                    sum+=b[j].sum;
                if(a[j].num!=b[i].num)
                    sum+=a[j].sum;
                if(c[j].num!=b[i].num)
                    sum+=c[j].sum;
                if(c[j].num==a[j].num)
                    sum=sum-min(a[j].num,c[j].num);
            }
            maxn=max(maxn,sum);
            sum=c[i].sum;
            for(int j=1;j<=n/2;j++)
            {
                if(j!=i)
                    sum+=c[j].sum;
                if(a[j].num!=c[i].num)
                    sum+=a[j].sum;
                if(b[j].num!=c[i].num)
                    sum+=b[j].sum;
                if(a[j].num==b[j].num)
                    sum=sum-min(b[j].num,a[j].num);
            }
                maxn=max(maxn,sum);
        }
        cout << maxn << endl;
    }
    return 0;
}
