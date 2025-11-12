#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int b[200005];
long long xo(int x,long long y){
    long long z=0;
    long long t=0;
    for(long long i=1;i<=20;i++){
    z*=2;
    if(x%2!=y%2){
        z+=1;
    }
    x/=2;
    y/=2;
    }
    for(long long i=1;i<=20;i++){
        t*=2;
        t+=z%2;
        z/=2;
    }
    return t;
}

//-------------------------------------------
int main(){
    freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
long long n,m=1,k=1,f=0,ans=0,cnt=0;

cin>>n>>k;
cin>>a[1];
if(a[1]==1||a[1]==0){
    cnt++;
}
for(long long i=2;i<=n;i++){
    cin>>a[i];
    b[i]=a[i];
    if(a[i]==1||a[i]==0){
        cnt++;
    }
    a[i]=xo(a[i],a[i-1]);
}
if(cnt=n&&n>1000){
    if(k==1){
    for(int i=1;i<=n;i++){
        if(b[i]==1){
            ans++;
        }
    }
    }
    else{
        for(int i=1;i<=n;i++){
            if(i<n){
                if(b[i]==1&&b[i+1]==1){
                    ans++;
                }
            }
            if(!b[i]){
                ans++;
            }
        }
    }
}
else{
while(m!=n){
    f=0;
    for(long long i=m;i<=n&&f==0;i++){
        if(a[i]==k&&m==1){
            f=1;
            ans++;
            m=i+1;

        }
        for(long long j=i;j>=m;j--){

        if(xo(a[i],a[j-1])==k){
            f=1;
            ans++;
            m=i+1;
        }
        }
    }
    if(f==0){
        m=n;
    }
}
}
cout<<ans;
fclose(stdin);
fclose(stdout);
return 0;
}
