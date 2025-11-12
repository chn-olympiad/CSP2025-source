#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],k,n;
int check2(int i,int j){
    if(i==j){
        return a[i];
    }
    else{
        int ans=a[i];
        for(int k=i+1;k<=j;k++){
            ans=ans^a[k];
        }
        return ans;
    }
}
bool check(int mid){
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(check2(i,j)==k){
                cnt++;
                i=j+1;
                j=i;
            }
        }
    }
    if(cnt>=mid){
        return 1;
    }
    return 0;
}
int f(int le,int ri){
    if(le>ri){
        return ri;
    }
    int mid=(le+ri)/2;
    if(check(mid)==1){
        return f(mid+1,ri);
    }
    else{
        return f(1,mid-1);
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    cout<<f(1,n);
    return 0;
}

