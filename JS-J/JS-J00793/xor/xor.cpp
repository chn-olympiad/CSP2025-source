#include<bits/stdc++.h>
using namespace std;
int n,k,q1,q2;
bool q,w;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            q=1;
            q1++;
        }
        if(a[i]==1){
            q2++;
        }
        if(a[i]!=0&&a[i]!=1) w=1;
    }
    if(k==0&&q==0&&w==0){
        cout<<n/2;
    }else if(q==1&&w==0){
        if(k==0){
            cout<<q1+q2/2;
        }else{
            cout<<q2;
        }
    }
    return 0;
}

