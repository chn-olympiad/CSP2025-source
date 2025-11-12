#include<bits/stdc++.h>


using namespace std;

int main()
{
    int n,num,ax,b,c;
    cin>>n;
    int a[5000];

    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int m = 3;m<=n;++m)
    {
        for(int i = 0 ; i <= n ; ++i)
        {
            for(int k=0;k<=n-m;++k){
                for(int j = i;j<=m+i;++j)
                {
                    if(a[j]>=ax)
                        ax=a[j];

                }
                for(int j = i;j<=m+i;++j)
                {
                    b=b+a[i];
                }
                if(b>2*ax)
                    num+=1;
                ax=0;b=0;
            }
        }
    }

    cout<<num/2;

    return 0;

}
