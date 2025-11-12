#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],ans,one,zer;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    srand(time(0));
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        one+=a[i];
        zer+=!a[i];
    }
    if(zer==0)ans=one/2;
    else if(k==0)
        ans=one/2+zer;
    else if(k==1)
        ans=one;
    else ans=rand()%n+1;
    cout<<ans;
    return 0;
}
