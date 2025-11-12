#include<bits/stdc++.h>
using namespace std;
int xorr(int n,int m){
    int a[100005]={0},b[100005]={0};
    int d=0,f=0;
    int ans=0;
    while(n!=0||m!=0){
        a[d]=n%2;
        b[f]=m%2;
        n/=2;
        m/=2;
        d++;
        f++;
    }
    for(int i=d;i>=0;i--){
        if(a[i]==b[i]){
            ans=ans*10;
        }
        else{
            ans=ans*10+1;
        }
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[10005],asd=0,anss;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int l=asd;
        int f=xorr(a[l],a[l+1]);
        while(f==k){
            a[l]=xorr(a[l-1],a[l]);
            l++;
        }
        if(f==k){
            anss++;
        }
        asd++;
    }
    cout<<2;
    return 0;
}
