#include<bits/stdc++.h>
using namespace std;
int a[50000000],n,ss,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>ss;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int l=0;
            for(int k=i;k<=j;k++){
                l=l^a[k];
            }
            if(l==ss){
                cnt++;
                i=j+1;
            }
        }
    }
    cout<<cnt;
    return 0;
}
