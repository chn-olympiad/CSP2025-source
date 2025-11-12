#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,p,po;
    cin>>n>>m;
    int s[n*m];
    for(int i=0;i<n*m;i++)
        cin>>s[i];
    p=s[0];
    sort(s,s+n*m,greater<int>());
    for(int i=0;i<n*m;i++)
        if(s[i]==p)
        {
            po=i+1;
            break;
        }
    if(po%n==0)
        cout<<po/n<<' '<<n;
    else
    {
        int c=po/n+1,r;
        if((po/n)%2==1)
            r=n-(po-(po/n)*n)+1;
        else
            r=po-(po/n)*n;
        cout<<c<<' '<<r;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
