#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
    int a[5];
};
node b[100500];
void dog(int i)
{

    int a1=b[i].a[1],a2=b[i].a[2],a3=b[i].a[3];
    if(a1>=a2&&a1>=a3)b[i].z=1;
    if(a2>=a1&&a2>=a3)b[i].z=2;
    if(a3>=a1&&a3>=a2)b[i].z=3;
    int maxx=max(max(a1,a2),a3);
    int minn=min(min(a1,a2),a3);
    b[i].x=maxx;
    b[i].y=maxx-(a1+a2+a3-maxx-minn);

}
bool cmp(node a,node b)
{
    if(a.y==b.y)return a.x>b.x;
    else return a.y>b.y;

}
int t,n,sum,cnt[10];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt[1]=0;
        cnt[2]=0;
        cnt[3]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>b[i].a[1]>>b[i].a[2]>>b[i].a[3];
            dog(i);
        }
        sort(b+1,b+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            sum+=b[i].x;
            cnt[b[i].z]++;
            if(cnt[b[i].z]==n/2)
            {
                for(int j=i+1;j<=n;j++)
                {
                    b[j].a[b[i].z]=0;
                    dog(j);
                }
                cnt[b[i].z]=0;
                sort(b+i+1,b+n+1,cmp);
            }
        }
        cout<<sum<<endl;
        sum=0;
    }


}

