#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[105];
    int sum=1;
    for (int i=2;i<=n*m;i++)
    {
        cin>>arr[i];
        if (arr[i]>arr[1])
        {
            sum++;
        }
    }
    int num1=sum/n,num2=sum%n;
    if (num1%2==1)
    {
        cout<<num1<<" "<<num2;
    }
    else cout<<num1<<" "<<n-num2;
    return 0;
}
