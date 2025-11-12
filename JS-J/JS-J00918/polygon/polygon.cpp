#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<"1"<<endl;
        }else{
            cout<<"0"<<endl;
        }
    }
    else if(a[n]==1){
        cout<<n-2<<endl;
    }
    else cout<<"1";
    return 0;
}
