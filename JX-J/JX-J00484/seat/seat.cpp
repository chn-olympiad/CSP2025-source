#include<bits/stdc++.h>
using namespace std;
int a[31][31];
struct student
{
    int b;
    int id;
}s[1001];
bool cmp(student q,student p)
{
    return q.b>p.b;
}
int n,m,k=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>s[i].b;
        s[i].id=i;
    }
    sort(s+1,s+n*m+1,cmp);
    for (int i=1;i<=n;)
    {
        for (int j=1;j<=m;j++)
        {
            k++;
            if(s[k].id==1)
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
        i++;
        for (int j=m;j>=1;j--)
        {
            k++;
            if(s[k].id==1)
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
        i++;
    }

    return 0;
}
