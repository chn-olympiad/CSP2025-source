#include<bits/stdc++.h>
using namespace std;
int a[6000000];
long long n,k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int ma,mi;
    ma=-1;
    mi=10000000;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ma=max(a[i],ma);
        mi=min(a[i],mi);
    }
    if(k==0){
        if(ma==mi){
        cout<<n/2;
        return 0;
        }
    }
    int lil=0;
    int yil=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i+1])
        {
            lil++;
            i++;
        }
    }
    for(int i=1;i<n;i++)
    {
        if((a[i]==1&&a[i+1]==0)||(a[i]==0&&a[i+1]==1))
        {
            yil++;
            i++;
        }
    }
    if(k==0)
        cout<<lil;
    else
    if(k==1)
        cout<<yil;
    else
        cout<<0;

    fclose(stdin);
   fclose(stdout);
    return 0;

}
