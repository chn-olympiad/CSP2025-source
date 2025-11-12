#include<bits/stdc++.h>
using namespace std;
int a[110]={0};
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
    int r,p;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];

    }
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    int pn,pm,cnt=0;
    for(int i=1;i<=m;i++)
    {
        pm=i;
        for(int j=1;j<=n;j++)
        {
            cnt++;
            if(pm%2)
                pn=j;
            else
                pn=n-j+1;

            if(r==a[cnt])
            {
                cout<<pm<<' '<<pn<<endl;
                return 0;

            }


        }



    }




    return 0;
}
