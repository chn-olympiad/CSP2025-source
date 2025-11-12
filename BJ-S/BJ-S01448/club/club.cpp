#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+5;
int t;
int n;
int idx1,idx2,idx3;
int maxk=-1e9;

struct node
{
    ll _1,_2,_3;
}a[N],one[N],two[N],three[N];//一部门，二部门，三部门

bool cmp(node x,node y)
{
    if(x._1!=y._1) return x._1>y._1;
    else if(x._2!=y._2) return x._2>y._2;
    else return  x._3>y._3;
}

void dfs(int k,int sum,int acnt,int bcnt,int ccnt)
{
    if(k==n+1)
    {
        if(acnt<=n/2&&bcnt<=n/2&&ccnt<=n/2)
        {
            maxk=max(maxk,sum);
        }
        return ;
    }
    if(acnt>n/2||bcnt>n/2||ccnt>n/2)
    {
        return ;
    }
    for(int i=1;i<=3;i++)
    {
        if(i==1)
        {
            dfs(k+1,sum+a[k]._1,acnt+1,bcnt,ccnt);
        }
        if(i==2)
        {
            dfs(k+1,sum+a[k]._2,acnt,bcnt+1,ccnt);
        }
        else
        {
            dfs(k+1,sum+a[k]._3,acnt,bcnt,ccnt+1);
        }
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]._1 >> a[i]._2 >> a[i]._3;
        }
        if(n==2)
        {
            for(int i=1;i<=n;i++)
            {
                cin>>a[i]._1 >> a[i]._2 >> a[i]._3;
            }
            int maxx=-1e9;
            maxx=max(max(max(a[1]._1+a[2]._2,a[1]._1+a[2]._3),max(a[1]._2+a[2]._1,a[1]._2+a[2]._3)),max(a[1]._3+a[2]._1,a[1]._3+a[2]._2));
            cout<<maxx<<"\n";
        }
        else if(n<=30)
        {
            dfs(1,0,0,0,0);
            cout<<maxk<<"\n";
        }
        else
        {
            for(int i=1;i<=n;i++)
            {

                cin>>a[i]._1 >> a[i]._2 >> a[i]._3;
                int k=max(a[i]._1,max(a[i]._2,a[i]._3));
                if(k==a[i]._1)
                {
                    idx1++;
                }
            }
        }



    }
    return 0;
}
