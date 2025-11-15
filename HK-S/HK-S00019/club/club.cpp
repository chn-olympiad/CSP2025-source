#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long t,maxx=-1,s[100100][5];
ll only1[100100];
int go(long long i, long long a, long long b, long long c, long long sum, long long n){
    long long suma=sum,sumb=sum,sumc=sum;
    if(i==n){
        if(a<n/2) suma=sum+s[i][1];
        if(b<n/2) sumb=sum+s[i][2];
        if(c<n/2) sumc=sum+s[i][3];
        return max(suma,max(sumb,sumc));
    }else{
        if(a<n/2) suma=go(i+1, a+1, b, c, sum+s[i][1], n);
        if(b<n/2) sumb=go(i+1, a, b+1, c, sum+s[i][2], n);
        if(c<n/2) sumc=go(i+1, a, b, c+1, sum+s[i][3], n);
        return max(suma,max(sumb,sumc));
    }
}

int go2(long long i, long long a, long long b, long long sum, long long n){
    long long suma=sum,sumb=sum;
    if(i==n){
        if(a<n/2) suma=sum+s[i][1];
        if(b<n/2) sumb=sum+s[i][2];
        return max(suma,sumb);
    }else{
        if(a<n/2) suma=go2(i+1, a+1, b, sum+s[i][1], n);
        if(b<n/2) sumb=go2(i+1, a, b+1, sum+s[i][2], n);
        return max(suma,sumb);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        long long n,ans=0; cin>>n;
        bool no2=1, no3=1;
        for(long long i=1;i<=n;i++){
            cin>>s[i][1]>>s[i][2]>>s[i][3];
            if(s[i][2]>0) no2=0;
            if(s[i][3]>0) no3=0;
            only1[i]=s[i][1];
        }
        if(n<=30)ans=go(0,0,0,0,0,n);
        else if(no2&&no3){
            sort(only1+1,only1+1+n);
            for(ll i=n;i>n/2;i--)  ans+=only1[i];
        }else if(no3){
            ans=go2(0,0,0,0,n);
        }
        cout<<ans<<endl;
    }
return 0;
}
 /**/
