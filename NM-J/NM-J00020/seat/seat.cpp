#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int len=0;
    int a[101]={0};
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n*m;i++)
    {
        if(a[i]>a[0])
        {
            len++;

        }
    }
    int len1=floor(len/n);


    if(len1==0)
    {
        cout<<"1 "<<len+1;
        return 0;
    }
    if(len1%2==0)
    {
        int len2=len-len1*n;
        cout<<len1+1<<' '<<len2+1;

    }
    else
    {
        int len2=len-len1*n;
        cout<<len1+1<<' '<<len2+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
