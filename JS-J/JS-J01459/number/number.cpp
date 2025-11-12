#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    int isntnine=1;//[1000005];
    //memset(isnine,0,sizeof(isnine));

    string a;
    getline(cin,a);

    int numb[1000005];
    int k=1;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>=48&&a[i]<=57)
        {
            numb[k]=a[i]-'0';
            k++;
            //if(a[i]=='9')
            //{
            //    swap(numb[k],numb[isntnine]);
            //    isntnine++;
            //}
            //for(int j=1;j<=k;j++)
              //  {
             //       cout<<numb[j];

             //   }cout<<endl;
        }
    }

    //for(int i=1;i<=k;i++)
    //{
    //    cout<<numb[i];

    //}
    //187b90cv65a7943

    for(int i=1;i<k;i++)
    {
        //cout<<numb[i];
        for(int j=1;j<k;j++)
        {
            if(numb[j]<numb[j+1])
            {
                swap(numb[j],numb[j+1]);
            }
        }
    }

    for(int i=1;i<k;i++)
    {
        cout<<numb[i];

    }

    return 0;
}
