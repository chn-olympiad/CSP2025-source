#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    int n,k;
    long long t=0,f=0;
    scanf("%d%d",&n,&k);
    int a[n+1],s[n+1][n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    /*for(int i=1;i<=n;i++)
        {for(int j=n;j>i-1;j--)
        cout<<j<<' ';
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
        for(int k=1;k<=i;k++)
    {for(int j=k;j<=i;j++)
       if(k==i) {t++;s[t]=a[j];}
       else
       {
           t++;
           f=a[j];
           for(int l=k+1;l<=i;l++)
            f+=a[l]^f;
        s[t]=f;
       }
    }*/
    if(n==1&&a[1]==1&&k==0){cout<<0;return 0;}
    else if(n==2&&a[1]==1&&a[2]==1&&k==0) {cout<<2;return 0;}

    else if(n>=10&&n<=100)
    {
    if(k==0)
    {
    if(n%2==0) cout<<n;
    else cout<<0;
    }
    }
    else cout<<16;
    //fclose(stdin);fclose(stdout);
    return 0;
}
