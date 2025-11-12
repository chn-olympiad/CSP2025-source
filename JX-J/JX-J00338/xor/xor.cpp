#include <bits/stdc++.h>
using namespace std;
int h(int n){
    int p=0;
    int l=0;
    while(n>=1){
        p+=n%10*pow(2,l);
        l++;
        n/=10;
    }
    return p;
}
int t(int n){
    int k=0;
    int p=0;
    while(n>=1){
        p++;
        int l=n%2;
        for(int i=1;i<=p-1;i++){
            l*=10;
        }
        k+=l;
        n/=2;
    }
    return k;
}
int yh(int a,int b){
    int x=t(a);
    int y=t(b);
    int j=0;
    int l=0;
    int z=x;
    int q=y;
    if(z!=0&&q!=0){
        while(z>=1&&q>=1){
        int n=z%10;
        int m=q%10;
        if(n!=m) j+=pow(10,l);
        z/=10;
        q/=10;
        l++;
        }
        if(z<1&&q>=1){
            int k=z;z=q;q=k;
        }
        while(z>=1||q>=1){
            if(z%10==1) j+=pow(10,l);
            z/=10;
            l++;
        }
    }
    else if(x==0||y==0){
        if(x==y) j=0;
        else j=1;
    }
    if(x==y&&x!=0&&y!=0){
        j=x;
    }
    j=h(j);

    return j;
}
int main(){
    freopen("xor.in",'r',stdin);
    freopen("xor.out",'w',stdout);
    int g,d;
    int n,k;
    int a[500001];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int h=0;
    int f=-1;
    for(int i=1;i<=n;i++){
        if(i<=f) continue;
        int p=a[i];
        if(p==k){
            h++;
            p=0;
            continue;
        }
        for(int j=i+1;j<=n;j++){
            p=yh(p,a[j]);
            if(p==k){
                h++;
                p=0;
                f=j;
            }
        }
    }
    cout<<h;
    return 0;
}
