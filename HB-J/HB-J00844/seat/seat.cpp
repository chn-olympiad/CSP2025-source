#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int brr[n*m+1]={0};
    int crr[n*m+1]={0};
    for (int i=1;i<=n*m;i++)
    {
        cin>>brr[i];
    }
    int Rmine=brr[1];
    sort(brr+1,brr+n*m+1);
    for (int i=1;i<=n*m;i++)
    {
        crr[i]=brr[n*m-i+1];
    }
    for (int i=1;i<=n*m;i++)
    {
        if (crr[i]==Rmine)
        {
            if (i%n==0)
            {
                int ceq=i/n;
                if (ceq%2==0)
                    cout<<ceq<<" "<<1;
                else
                    cout<<ceq<<" "<<n;
            }
            else if (n%2==0)
            {
                cout<<i/n+1<<" "<<(i%n)+1;
            }
            else
            {
                cout<<i/n+1<<" "<<i%n;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
