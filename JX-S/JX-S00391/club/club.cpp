#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t,sum;
int book[5],yong[N];

struct node
{
    int num;
    int leb;
} maxl[N];
bool cmp(node x,node y)
{
    return x.num>y.num;
}


int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int j=1; j<=t; j++)
    {
        book[1]=0;
        book[2]=0;
        book[3]=0;
        cin>>n;
        for(int i=1,e,r,o; i<=n; i++)
        {
            cin>>e>>r>>o;
//cout<<endl<<e<<r<<o<<endl;
            yong[i]=0;
            if(e>r)
            {
                maxl[i].num=e;
                maxl[i].leb=1;
            }
            if(r>=e)
            {
                maxl[i].num=r;
                maxl[i].leb=2;
            }
            if(o>maxl[i].num)
            {
                maxl[i].num=o;
                maxl[i].leb=3;
            }

        }

        sort(maxl+1,maxl+n+1,cmp);
        for(int l=1; l<=n; l++)
        {
            if(yong[l]!=0)
            {
                continue;
            }
            book[maxl[l].leb]++;
            //  cout<<book[maxl[l].leb];
            if(book[maxl[l].leb]>n/2)
            {
                book[maxl[l].leb]--;
                continue;
            }

            yong[l]=1;
            sum+=maxl[l].num;
        }
        cout<<sum<<endl;
        sum=0;
    }


    return 0;
}

