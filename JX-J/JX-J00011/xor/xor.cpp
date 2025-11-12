#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    bool wu=false;
    while(true){
        int i=0,j=1;
        while(true){
            int sum=a[i]^a[j];
            i+=j;
            j=i+1;
            if(j>n){
                wu=true;
                break;
            }
            if(sum==k){
                cnt++;
                break;
            }
            else{
                j++;
            }
        }
        if(wu==false){
            cout<<cnt;
            break;
        }
    }
    return 0;
}

