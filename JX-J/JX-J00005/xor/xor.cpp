#include<bits/stdc++.h>
using namespace std;
int d(int a,int b){
    if(a==0||b==0){
        return -(a+b);
    }
    else{
        return a+b;
    }

}
int q[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int sum=0,cnt=0;
    for(int i=1;i<=n;i++){
        cin>>q[i];
    }
    for(int i=1;i<=n;i++){
        if(sum==0){
            sum+=q[i];
        }
        if(i!=n){
            sum=d(sum,q[i+1]);
        }
        if(q[i]==k||sum==k){
            sum=0;
            cnt++;
        }

    }
    cout<<cnt;
    return 0;
}
