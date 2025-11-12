#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n;
int a[N];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<1;
            return 0;
        }
    }
    for(int i=1;i<=n-2;i++){
        for(int j=2;j<=n-2;j++){
            for(int k=3;k<=n;k++){
                if(a[i]+a[j]>a[k])
                    cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
/*
for(int p=4;p<=n;p++){
    for(int q=5;q<=n;q++){

    }
}
*/
