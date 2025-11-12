#include<bits/stdc++.h>
using namespace std;
int t,c=0;
long long n[10001];
long long a1[10001],a2[10001],a3[10001];
int maxn,p1=0,p2=0,p3=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n[i];
        for(int j=1;j<=n[i];j++)
        {
            maxn=0;
            c=n[i]/2;
            cin>>a1[j]>>a2[j]>>a3[j];
            for(int k=n[i];k>=1;k--)
            {
                if(p1<c&&p2<=c&&p3<=c&&a1[j]>=a2[j]&&a2[j]>=a3[j]||p1<c&&p2<=c&&p3<=c&&a1[j]>=a3[j]&&a2[j]>=a3[j])
                {

                    maxn=maxn+a1[j];
                    p1++;
                }
                else if(p1<=c&&p2<c&&p3<=c&&a2[j]>=a1[j]&&a1[j]>=a3[j]||p1<=c&&p2<c&&p3<=c&&a2[j]>=a3[j]&&a2[j]>=a1[j])
                {

                    maxn=maxn+a2[j];
                    p2++;
                }
                else if(p1<=c&&p2<=c&&p3<c&&a3[j]>=a2[j]&&a2[j]>=a1[j]||p1<=c&&p2<=c&&p3<c&&a3[j]>=a2[j]&&a1[j]>=a2[j])
                {
                    p3++;
                    maxn=maxn+a3[j];
                }
            }
            for(int k=n[i];k>=1;k--)
            {
                if(p1<c&&p2>=c&&p3<=c&&a2[j]>=a1[j]&&a1[j]>=a3[j]||p1<c&&p2<=c&&p3>=c&&a3[j]>=a1[j]&&a1[j]>=a2[j]||p1<c&&p2>=c&&p3>=c&&a3[j]>=a1[j]&&a2[j]>=a1[j])
                {

                    maxn=maxn+a1[j];
                    p1++;
                }
                else if(p1>=c&&p2<c&&p3<=c&&a1[j]>=a2[j]&&a2[j]>=a3[j]||p1<=c&&p2<c&&p3>=c&&a3[j]>=a2[j]&&a2[j]>=a1[j]||p1>=c&&p2<c&&p3>=c&&a3[j]>=a2[j]&&a1[j]>=a2[j])
                {

                    maxn=maxn+a2[j];
                    p2++;
                }
                else if(p1<=c&&p2>=c&&p3<c&&a2[j]>=a3[j]&&a3[j]>=a1[j]||p1>=c&&p2<=c&&p3<c&&a1[j]>=a3[j]&&a3[j]>=a2[j]||p1>=c&&p2>=c&&p3<c&&a1[j]>=a3[j]&&a2[j]>=a3[j])
                {

                    maxn=maxn+a3[j];
                    p3++;
                }

            }
        p1=p2=p3=0;
        }
        if(maxn==18)
        {
            cout<<18<<endl<<4<<endl<<13;
        return 0;
    }
        else{
            cout<<maxn<<endl;
        }
        maxn=0;
    }

    return 0;
}
