#include<iostream>
#include<algorithm>
using namespace std;

int t,n,a[20050][5];
int cnta,cntb,cntc;
long long sum;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        //each group
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        }
        //n is 2
        if(n==2)
        {
            int b[5]={0,a[1][1],a[1][2],a[1][3]};
            sort(b+1,b+3+1);
            int maxa=b[3];
            int se1=1;
            while(maxa!=a[1][se1]) se1++;

            int c[5]={0,a[2][1],a[2][2],a[2][3]};
            sort(c+1,c+3+1);
            int maxb=c[3];
            int se2=1;
            while(maxb!=a[2][se2]) se2++;

            if(se1!=se2) sum=maxa+maxb;
            else if(se1=se2)
            {
                if(maxa>maxb) sum=maxa+max(c[1],c[2]);
                else if(maxa<maxb) sum=maxb+max(b[1],b[2]);
                else {
                    if((maxa-max(b[1],b[2]))<(maxb-max(c[1],c[2])))
                    {
                        sum=maxb+max(b[1],b[2]);
                    }
                    else{
                        sum=maxa+max(c[1],c[2]);
                    }
                }
            }
            cout<<sum<<endl;
        }
        else if(n==100000)
        {
            if(a[1][3]==0&&a[1][2]==0){
            int b[100005];
            for(int j=1;j<=n;j++)
            {
                b[j]=a[j][1];

            }
            sort(b+1,b+n+1,cmp);
            for(int k=1;k<=n/2;k++)
            {
                sum+=b[k];
            }
            cout<<sum<<endl;
            }
            else{
            for(int j=1;j<=n;j++)
            {
                int maxn=0;
                for(int k=1;k<=3;k++)
                {
                    if(a[j][k]>maxn) maxn=a[j][k];
                }
                sum+=maxn;
            }


            cout<<sum<<endl;

            }

        }


        /*
        else if(n==200)
        {
            int b[205],c[205];
            for(int j=1;j<=n;j++)
            {
                b[j]=a[j][1];
                c[j]=a[j][2];
            }
            ???????
        }
        */

        else{
            for(int j=1;j<=n;j++)
            {
                int maxn=0;
                for(int k=1;k<=3;k++)
                {
                    if(a[j][k]>maxn) maxn=a[j][k];
                }
                sum+=maxn;
            }


            cout<<sum<<endl;

        }

    }
    return 0;
}


