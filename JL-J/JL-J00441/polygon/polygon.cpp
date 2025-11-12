#include<bits/stdc++.h>
using namespace std;
bool m[10000];
int a;
int f(int aa,int b){
    int p=1;
    for(int i=0;i<b;i++){
        p*=aa;
    }
    return p;
}
void f2(int aa,int b){
    for(int i=0;i<b;i++){
        m[i]=aa%2;
        aa=aa/2;
    }
}
int p6(int aa,int b){
    int p=1;
    for(int i=0;i<b;i++){
        p*=aa;
        p=p%998244353;
    }
    return p-a*(a-1)/2-a-1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    long long ans=0;
    cin>>a;
    int A[a];
    for(int i=0;i<a;i++){
        cin>>A[i];
    }
    int o=1;
    for(int i=0;i<a;i++){
        if(A[i]!=1){
            o=0;
            break;
        }
    }
    if(o){
        cout<<p6(2,a);
        return 0;
    }
    for(int i=0;i<a;i++){
        int t;
        for(int j=0;j<a-1;j++){
            if(A[j]>A[j+1]){
                t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
        }
    }
    int s;
    for(int i=a-1;i>=2;i--){
        for(int j=0;j<f(2,i);j++){
            f2(j,i);
            s=0;
            for(int k=0;k<i;k++){
                s+=A[k]*m[k];

            }
            if(s>A[i]){
                ans++;
                ans=ans%998244353;
            }
        }
    }
    cout<<ans;
}
