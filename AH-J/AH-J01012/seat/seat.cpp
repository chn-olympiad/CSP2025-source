#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    int a[k+1];
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    int a1=a[1];
    sort(a+1,a+k+1,greater<int>());
    for(int i=1;i<=k;i++)
    {
        if(a1==a[i])
        {
            int shang=i/n;
            int yu=i%n;
            if(shang%2==0)
            {
                cout<<shang+1<<" "<<yu;
            }
            else cout<<shang+1<<" "<<m-yu;
            return 0;
        }
    }
}
