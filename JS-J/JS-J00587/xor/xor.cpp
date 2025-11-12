#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],ans;
bool f=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==1){
      for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp)ans++;
      }
    }else{
      for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(!tmp)ans++;
        else{
            if(f){
                f=0;ans++;
            }else{
                f=1;
            }
        }
      }
    }

    cout<<ans;
return 0;
}



























