#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
long long n,k,cnt=0;
cin>>n>>k;
for(int i=0;i<n;i++){
    cin>>a[i];
}
if(k==0){
    for(int i=0;i<n;i++){
        if(a[i]==1){
            cout<<(n+1)*n/2-n;
            return 0;
        }else{
        if(a[i]==0){
            cnt++;
        }
        if(a[i]==a[i+1]){
            cnt++;
        }
        }
    }
    cout<<cnt;
    return 0;
}else if(k==1){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            cnt++;
        }
    }
    return 0;
}
cout<<"0";
return 0;
}
