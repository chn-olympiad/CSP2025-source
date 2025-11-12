#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,m,b[3];
    cin>>n;
    int t[6]={0};
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int a[3];
            cin>>a[0]>>a[1]>>a[2];
            sort(a,a+3);
            t[i]+=a[2];
        }
    }
    for(int i=0;i<n;i++) cout<<t[i];
    return 0;
}
