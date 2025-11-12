#include<bits/stdc++.h>
using namespace std;
int n,ans;
vector<int> a,b,c;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.begin()+n);
    for(int i=0;i<n;i++){
        b[i]=a[i];
        c[i]=a[i];
    }
    for(int i=0;i<n;i++){
        b[i]+=b[i-1];
        c[i]*=2;
    }
    for(int i=0;i<n;i++){
        if(b[i]>c[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
