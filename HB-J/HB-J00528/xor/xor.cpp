#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a[100005],b[100005],sum;
int x(int l,int r){
    if(l==r) return a[l];
    else if(l==1) return b[r];
    else return b[r]^b[l-1];
}
bool cc(int l,int r){
    for(int i=l;i<=r;i++){
        if(a[i]==-1) return 1;
    }
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    b[1]=a[1];
    for(int i=2;i<=n;i++){
        b[i]=b[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j+i-1<=n;j++){
            if(cc(j,j+i-1)==0 && x(j,j+i-1)==k){
                for(int m=j;m<=j+i-1;m++) a[m]=-1;
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}
