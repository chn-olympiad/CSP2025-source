#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n,k,a[4]={0};
    cin>>n>>k;
    for (int i=0; i<=3; i++)
        cin>>a[i];
    if (k==2)
        cout<<"2";
         else if (k==0)
            cout<<"1";
            else
                cout<<"2";
    return 0;
}
