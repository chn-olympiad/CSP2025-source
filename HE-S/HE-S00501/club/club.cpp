#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int h[5]={ },a=0;
    int t;
    cin>>t;
    while(t--){
        int n,a1[100005],a2[100005],a3[100005],x[100005];
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
        }for(int i=1;i<=n;i++){
            x[i]=max(max(a1[i],a2[i]),a3[i]);
        }for(int i=1;i<=n;i++){
            h[a]+=x[i];
        }a++;
    }for(int i=1;i<=t;i++){
        cout<<h[i]<<endl;
    }
    return 0;
}
