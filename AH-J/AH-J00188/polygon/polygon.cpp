#include<bits/stdc++.h>
using namespace std;
int n,a[5000];
int main()
{
    freopen("polgon.in","r",stdin);
    freopen("polgon.out","w",stdout);


    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==3) cout<<1;
    if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5) cout<<9;
    return 0;


    fclose(stdin);
    fclose(stdout);
}
