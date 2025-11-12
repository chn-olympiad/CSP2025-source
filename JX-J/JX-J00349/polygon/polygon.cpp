#include<bits/stdc++.h>
using namespace std;
string a[100005];
int b[100005];
void c(int x,int i){
    while(x!=0){
        a[i]+=x%2;
        x/=2;
    }
}
int main(){
    int n,k;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>b[i];
        c(b[i],i);
    }
    int l1=0,r1=0,l2=0,r2=n-1,d=0;
    for(int i=0;i<n;i++){
        if(d+b[i]==k){
            r1=i;
            l2=i+1;
        }
        d+=b[i];
    }
    for(int i=l1;i>=r1;i++){

    }
    return 0;
}
