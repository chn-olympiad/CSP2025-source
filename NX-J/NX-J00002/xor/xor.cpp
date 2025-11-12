#include<bits/stdc++.h>
using namespace std;
bool v[500005]={0};
bool inside(int a,int b){
    for(int i=a;i<=b;i++){
        if(v[i]){
            return false;
        }

    }
    return true;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    long long a[n+5]={0};
    long long l[n+5]={0};

    for(int i=1;i<=n;i++){
        int aa;
        cin>>aa;
        a[i]=aa;
        l[i]=l[i-1]^a[i];
        v[i]=0;
    }
    int c=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((l[j]^l[i-1])==k && inside(i,j)){
                for(int k=i;k<=j;k++){
                    v[k]=1;
                }
                c++;
            }
        }
    }
    cout<<c;
    return 0;
}
