#include <bits/stdc++.h>
using namespace std;
int a[1000005],n,k,s;
int f(int x,int y){
    int q[1000],p[1000],i = 0,j = 0,d,z,m = 1;
    while(x!=0){
        q[i]= x%2;
        x/=2;
        i++;
    }
    while(y!=0){
        p[i] = y%2;
        y/=2;
        j++;
    }
    for(int k = max(i,j)-1;k>=0;k++){
        if(p[k]==q[k])d=0;
        else d=1;
        z+=d*m;
        m*=2;
    }
    return z;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    int b = a[1];
    for(int i = 2;i<=n;i++){
        int c = 0;
        if(b==k)s++;
        for(int j = 1;j<=i;j++){
            b=f(b,a[j]);
            c++;
        }
        if(b==k)s = max(s,c);
        b=a[i];
    }
    cout<<s;
    return 0;
}
