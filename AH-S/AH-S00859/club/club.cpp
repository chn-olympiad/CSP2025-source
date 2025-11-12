#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node2{
    int satis[4];
    int newsatis[4];
    int fc;
}people[100005];
struct node{
    int member[100005];
    int cnt;
    int sum;
}tc[4];
int getmax(int a,int b,int c)
{
    if(a>=b&&a>=c) return 1;
    if(b>=c&&b>=a) return 2;
    if(c>=a&&c>=b) return 3;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=3;j++){tc[j].cnt=0;tc[j].sum=0;}
        for(int j=1;j<=n;j++) cin>>people[j].satis[1]>>people[j].satis[2]>>people[j].satis[3];
        for(int j=1;j<=n;j++)
        {
            people[j].newsatis[1]=people[j].satis[1];
            people[j].newsatis[2]=people[j].satis[2];
            people[j].newsatis[3]=people[j].satis[3];
            people[j].fc=getmax(people[j].satis[1],people[j].satis[2],people[j].satis[3]);//fc is the max xuhao of every inputline
            sort(people[j].newsatis+1,people[j].newsatis+4);
        }
        for(int j=1;j<=n;j++) people[j].fc=getmax(people[j].satis[1],people[j].satis[2],people[j].satis[3]);
        for(int j=1;j<=n;j++)
        {
            if(people[j].fc==1)
            {
                if(tc[1].cnt+1<=(n/2))
                {
                    tc[1].member[++tc[1].cnt]=j;
                    tc[1].sum+=people[j].satis[1];
                }
                else
                {
                    tc[2].member[++tc[2].cnt]=j;
                    tc[2].sum+=people[j].newsatis[2];
                }
            }
            else if(people[j].fc==2)
            {
                if(tc[2].cnt+1<=(n/2))
                {
                    tc[2].member[++tc[2].cnt]=j;
                    tc[2].sum+=people[j].satis[2];
                }
                else
                {
                    tc[3].member[++tc[3].cnt]=j;
                    tc[3].sum+=people[j].newsatis[2];
                }
            }
            else
            {
                if(tc[3].cnt+1<=(n/2))
                {
                    tc[3].member[++tc[3].cnt]=j;
                    tc[3].sum+=people[j].satis[3];
                }
                else
                {
                    tc[1].member[++tc[1].cnt]=j;
                    tc[1].sum+=people[j].newsatis[2];
                }
            }
        }
        cout<<tc[1].sum+tc[2].sum+tc[3].sum<<"\n";
    }
    return 0;
}
