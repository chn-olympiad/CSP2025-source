#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[500002];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
int l=1,r=1;
int h=a[1];
if(m==0){
    for(int i=1;i<=n;i++){
            if(a[i]==0){
            ans++;
            continue;
            }
            else if(a[i]==a[i+1]){
            i++;
            ans++;
            }
        }

    cout<<ans;
    return 0;
}
while(true){
    if(h==m){
       ans++;
       r++;
       l=r;
       h=a[r];
    }
    if(r<n){
        r++;
        if(h^a[r]==m){
       ans++;
       r++;
       l=r;
       h=a[r];
        }
        if(h<m&&h^a[r]>=m){
            h^=a[r];
        }
        else if(h>m&&h^a[r]<=h){
            h^=a[r];
        }
        else if(r<=l){
            h^=a[r];
        }
        else{
            h^=a[l];
            l++;
            r--;
        }
    }
    else{
        h^a[l];
        l++;
        if(l>r)break;
    }
}
cout<<ans;
  return 0;
}
