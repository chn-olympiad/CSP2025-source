#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int x,id;
}a[105];
bool cmp(node x,node y)
{
    return x.x>y.x;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1].x;
    a[1].id=1;
    for(int i=2; i<=n*m; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+(n*m)+1,cmp);
    /*for(int i=1; i<=n*m; i++)
    {
        cout<<a[i].x<<" ";
    }*/
    for(int i=1; i<=n*m; i++)
    {
        if(a[i].id)
        {
            int lx,ly;
            ly=(i+n-1)/n;
            if(ly%2==1)
            {
                if(i%n==0)
                {
                    lx=n;
                }
                else
                {
                    lx=i%n;
                }
            }
            else
            {
                if(i%n==0) lx=1;
                else
                {
                    lx=n-(i%n)+1;
                }
            }
            cout<<ly<<" "<<lx;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
