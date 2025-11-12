#include<bits/stdc++.h>
using namespace std;
int laoda(int x){
    int o=x;
    string b;
    while(o){
        b+=to_string(o%2);
        o-=o%2;
        o/=2;
    }
    reverse(b.begin(),b.end());
    return stoi(b);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int h=a[i];
            for(int p=i+1;p<=j;p++){
                h=laoda(h)^laoda(a[p]);
            }
            if(h==k){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
