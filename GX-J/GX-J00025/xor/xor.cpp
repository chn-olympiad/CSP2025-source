#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],ans=0;
bool f=false;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
      if(a[i]==k){
        ans++;
      }
      else{
        while(f==false){
            for(int j=i;j<n;j++){
                a[j+1]=a[j]^a[j+1];
                if(a[j+1]==k){
                    ans++;
                    f=true;
                    i=j+2;
                }
            }
        }
        f=false;
      }
    }
    cout<<ans;
return 0;
}
