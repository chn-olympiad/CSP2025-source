#include<bits/stdc++.h>
using namespace std;
int n,a[10000],zuhe;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int x=n;x>=3;x--)
    {
        for(int i=1;i<=n-x+1;i++)
        {
            int c=0;
            priority_queue<int> pq;
            c=a[1];
            for(int j=i;j<=x;j++)
            {
                c+=a[i+j];
                pq.push(a[i+j]);
            }
            if(c>pq.top()*2)
                zuhe++;
        }
    }
    cout<<zuhe;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
