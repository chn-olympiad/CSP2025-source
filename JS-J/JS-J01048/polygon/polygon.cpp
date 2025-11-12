#include <bits/stdc++.h>

using namespace std;
int n,a[100000],sm = 0;
int main()
{

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        sm += a[i];
    }
    if(sm > max(max(a[0],a[1]),a[2]) * 2){
        cout<< 1;
    }else{
        cout<<0;
    }
    return 0;
}
