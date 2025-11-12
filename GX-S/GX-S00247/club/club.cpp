#include<bits/stdc++.h>
using namespace std;
int sum;
int a[100005][4];
int ans;
int j[4];
void DFS(int time,int z)
{
    if(time>ans)
    {
        if(z>sum)
        {
            sum=z;
        }
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(j[i]<ans/2)
        {
            j[i]++;
            DFS(time+1,z+a[time][i]);
            j[i]--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        cin>>ans;
        for(int i=1;i<=ans;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
        DFS(1,0);
        cout<<sum<<endl;
        sum=0;
        j[1]=0;
        j[2]=0;
        j[3]=0;
    }
    return 0;
}
