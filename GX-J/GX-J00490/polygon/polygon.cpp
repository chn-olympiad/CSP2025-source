#include<bits/stdc++.h>
using namespace std;

int main() {
int n,ans=0;
cin>>n;
int a[256];
for(int i=1;i<=n;i++){
    cin>>a[i];


}
if(n=3){
    if(a[1]+a[2]>a[3])
    {

        cout<<1;
        return 0;
    }
    else {
            cout<<0;
        return 0;
    }

}
if(n=4){
    if(a[1]+a[2]>a[3])
        ans++;
    if(a[1]+a[2]>a[4])
        ans++;
    if(a[1]+a[3]>a[4])
        ans++;
    if(a[2]+a[3]>a[4])
        ans++;
    if(a[1]+a[2]+a[3]>a[4])
        ans++;
    cout<<ans;


}

return 0;
}


