#include<bits/stdc++.h>
using namespace std;
int a[100005][5];

bool cmp(int a,int b)
{

    return a>b;
}

struct sub{
int d;
int id;
int maxx;};
sub dm[100005];
bool cmp2(sub a,sub b)
{

    return a.d<b.d;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T;
    cin>>T;
    while(T--)
    {

        memset(dm,0,sizeof(dm));

        int n;
        cin>>n;
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++)
        {

            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3])
            {

                 dm[i].maxx=a[i][1];
                 dm[i].d=a[i][1]-a[i][2];
                 dm[i].id=1;
                cnt1++;
            }
            else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2])
            {

                 dm[i].maxx=a[i][1];
                 dm[i].d=a[i][1]-a[i][3];
                 dm[i].id=1;
                cnt1++;
            }

            else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])
            {

                 dm[i].maxx=a[i][2];
                 dm[i].d=a[i][2]-a[i][1];
                 dm[i].id=2;
                cnt2++;
            }

            else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1])
            {

               dm[i].maxx=a[i][2];
                dm[i].d=a[i][2]-a[i][3];
                dm[i].id=2;
                cnt2++;
            }

            if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2])
            {

                dm[i].maxx=a[i][3];
                dm[i].d=a[i][3]-a[i][1];
                dm[i].id=3;
                cnt3++;
            }

            if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1])
            {

                dm[i].maxx=a[i][3];
                dm[i].d=a[i][3]-a[i][2];
                dm[i].id=3;
                cnt3++;
            }




        }
        int st=n/2;
        if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2)
        {
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                sum+=dm[i].maxx;

            }
            cout<<sum<<endl;
        }
        else {
            sort(dm,dm+n,cmp2);
            int num,maxid;
            {
                if(cnt1>cnt2&&cnt1>cnt3)
                {

                    num=cnt1;
                    maxid=1;
                }
                if(cnt2>cnt3&&cnt2>cnt1)
                {

                    num=cnt2;
                    maxid=2;
                }
                if(cnt3>cnt2&&cnt3>cnt1)
                {

                    num=cnt3;
                    maxid=3;
                }

            }
            int cntt=0;
            for(int i=1;i<=n;i++)
            {
                if(cntt==num-st)break;
                if(dm[i].id==maxid)
                {
                    dm[i].maxx-=dm[i].d;
                    cntt++;
                }

            }
            int sum=0;
            for(int i=1;i<=n;i++)
            {

                sum+=dm[i].maxx;
            }
            cout<<sum<<endl;

        }


    }

}
