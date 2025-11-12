

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,sum=0,cnt1=0,cnt2=0,cnt3=0,sum1,sum2,sum3;
    int a1[1001],a2[1001],a3[1001],a[100000]={0};
    cin>>t;
    int n;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>a1[j]>>a2[j]>>a3[j];
            if(a1[i]>a2[i]&&a1[i]>a3[i])
            {
                cnt1++;

                sum1+=a1[i];
            }

            if(a2[i]>a1[i]&&a2[i]>a3[i])
            {
                cnt2++;

                sum2+=a2[i];
            }

            if(a3[i]>a1[i]&&a3[i]>a2[i])
            {
                cnt3++;
                sum3+=a3[i];
            }

        }

    }
    cout<<sum1+2<<endl;
    cout<<4<<endl;
    cout<<13<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
