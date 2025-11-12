#include<bits/stdc++.h>
using namespace std;
int n,m,h=0,k=1,f=1;
int b[500010],a[500010];
int q(int l,int r){
    int fw=0;
for(int i=1;max(l,r)!=0;i*=2){
    int p=l&1,j=r&1;l/=2;r/=2;
    if(p!=j) fw+=i;
}
return fw;
}
int g(int f,int k){
    int w=0;
for(int i=f;i<=k;i++){
    for(int j=f;j<=i;j++){
        if(q(b[i],b[j])==m&&q(i,j)!=0)w++,f=i+1;
    }
}
return w;
}
int main(){
cin>>n>>m;cin>>a[1];b[1]=a[1];if(a[1]==m)k=2,h++;
for(int i=2;i<=n;i++){
    cin>>a[i];
    b[i]=q(b[i],a[i]);
    if(a[i]==m){f=k;k=i-1;h++;
    h+=g(f,k);k+=2;
    }
}
f=k;k=n;h+=g(f,k);
cout<<h;
return 0;
}
