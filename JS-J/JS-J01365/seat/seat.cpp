#include <bits/stdc++.h>
using namespace std;
int n,m,p;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[1]) p++;
    }
    p+=1;
    int row=p/n+(p%n!=0);

    if(row%2==1) cout<<row<<" "<<p%n+(p%n==0)*n;
    else cout<<row<<" "<<n+1-p%n-(p%n==0)*n;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
