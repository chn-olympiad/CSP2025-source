#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll k,ans,a[100010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int xors;
    for(int i=0;i<n;i++){
        int xors=a[i];
        for(int j=i+1;j<n;j++){
            if(xors==k) ans++;
            xors=xors^a[j];
        }
    }
    cout<<ans;



    return 0;
}
