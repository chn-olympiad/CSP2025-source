#include <bits/stdc++.h>

using namespace std;
int a[500014];
int n,k;

string s="";

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    int ans=0;
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)
              ans++;
        }
    }
    else if(k==0){
        int i=1;
        while(i<=n){
            if(a[i]==0){
                ans++;
                i++;
            }
            else if(a[i]==1){
                int p=i;
                while(a[i]==1) i++;
                ans+=(i-p)/2;
            }
        }
    }

    cout<<ans;
    return 0;
}
