#include<bits/stdc++.h>
using namespace std;
int ads(int x){
    int a[100];
    while(x<2){
        int i=0;
        a[i]=x%2;
        x/=2;
        i++;
    }
    return a[100];
}
int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    int n,k,a[500005],b=0,m=0;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            b+=1;
            m=i;
        }
    }
    for(int i=1;i<=m-1;i++){
        int q=0;
        for(int j=i;j<=m-1;j++){
            q=ads(a[j])|ads(a[j+1]);
        }
        if(q==k){
            b+=1;
            break;
        }
    }for(int i=m+1;i<=n-1;i++){
        int q=0;
        for(int j=i;j<=n-1;j++){
            q=ads(a[j])|ads(a[j+1]);
        }
        if(q==k){
            b+=1;
            break;
        }
    }
    cout << b << endl;
    return 0;
}
