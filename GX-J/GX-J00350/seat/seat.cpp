#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],sum,buk[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    buk[a[1]]=1;
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
        buk[a[i]]=1;
    }
    for(int i=100;i>=a[1];i--)
    {
        if(buk[i]==1)
            sum++;
    }
    int lie=sum/n;
    int hang;
    if(sum%n!=0)
        lie++;
    if(lie%2==1){
        if(sum%n==0)
            hang=n;
        else
            hang=sum%n;
    }
    else
        hang=n-sum%n;
    cout<<lie<<" "<<hang<<endl;
    return 0;
}
