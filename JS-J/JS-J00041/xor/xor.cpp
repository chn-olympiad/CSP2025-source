#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    //cout<<n<<endl;
    int ans=0,last_end=0;
    for(int i=0;i<n;i++){
        if(i<last_end){
            i=last_end;
        }
        int t=0;
        int j;
        for(j=i;j>=last_end;j--){
            t^=num[j];
            //cout<<num[i]<<" "<<j<<" "<<i<<" "<<t<<" "<<last_end<<endl;
            if(t==k){
                //cout<<j<<" "<<i<<" "<<last_end<<endl;
                ans++;
                last_end=i+1;
                //cout<<"yes:";
                break;
            }
        }
        //cout<<endl;
    }
    cout<<ans;
    return 0;
}