#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[1000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.ans","w",stdout);
    cin>>n;
    if(n==3)
    {
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int m=*max_element(a,a+n);
        if(a[0]+a[1]>max(a[0],a[1])*2) cnt++;
        if(a[2]+a[1]>max(a[2],a[1])*2) cnt++;
        if(a[0]+a[2]>max(a[0],a[2])*2) cnt++;
        if(a[0]+a[1]+a[3]>m*2) cnt++;
        cout<<cnt;
    }
    return 0;
}
