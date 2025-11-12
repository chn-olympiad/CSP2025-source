#include<bits/stdc++.h>
using namespace std;
int n,m,c,a[110];
priority_queue<int> pq;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a[1];
    c=a[1];
    pq.push(a[1]);
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
        pq.push(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=n;j++)
            {
                if(pq.top()==c)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                pq.pop();
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                if(pq.top()==c)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                pq.pop();
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
