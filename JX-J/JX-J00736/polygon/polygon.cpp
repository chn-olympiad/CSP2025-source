#include<bits/stdc++.h>
using namespace std;
long long n,t,a[5001];
int main()
{
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    for(int k=i;k<=n;k++)
    {for(int j=k;j<=n;j++)
        cout<<a[j]<<' ';
        cout<<endl;}
    //fclose(stdin);fclose(stdout);
    return 0;
}
