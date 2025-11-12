#include<bits/stdc++.h>
using namespace std;
const int N=110;
struct node
{
  int grade;
  int number;
}f[N];
int n,m,x;

bool cmp(node x,node y)
{
    return x.grade>y.grade;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>f[i].grade;
        f[i].number=i;
    }

    sort(f+1,f+1+n*m,cmp);

    for(int i=1;i<=n*m;i++)
    {
        if(f[i].number==1)
        {
            x=i;
            break;
        }
    }

    int j=1,i=1,num=1;
    while(num<x)
    {
        while(j<n&&num<x)
        {
            j++;num++;
        }

        if(num<x)
        {
        i++;num++;
        }

        while(j>1&&num<x)
        {
            j--;num++;
        }

        if(num<x)
        {
            i++;num++;
        }
    }
    cout<<i<<" "<<j<<endl;
    return 0;
}
