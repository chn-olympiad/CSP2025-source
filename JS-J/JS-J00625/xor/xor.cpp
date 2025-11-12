#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt;int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        bool f=0;int b=0;
        for(int j=i;j<n;j++){
                b=j;
                if(i==j){
                    if(a[i]==k){
                        cnt++;
                        f=1;
                        break;
                    }
                }
                if(i+1==j){
                    if((a[i]^a[j])==k){
                        cnt++;
                        f=1;
                        break;
                    }
                }
                if(i+1<j){
                    int sum=(a[i]^a[i+1]);
                    for(int k=i+2;k<=j;k++){
                        sum=(sum^a[k]);
                    }
                    if(sum==k){
                        cnt++;
                        f=1;
                        break;
                    }
                }
        }
        if(f){
            i=b;
        }
    }
    cout<<cnt;
return 0;
}
