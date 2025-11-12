#include<bits/stdc++.h>
using namespace std;
long long n,m,t,la;
long long a[500005];
long long yh(long long i,long long j){
    string s="",x="";
    while(i){
        s+=char(i%2);
        i/=2;
    }
    while(j){
        x+=char(j%2);
        j/=2;
    }
    long long l=1,ans=0;
    if(s.size()>x.size()){
        for(int a=x.size();a<s.size();a++)
            x='0'+x;
    }else{
        for(int a=s.size();a<x.size();a++)
            s='0'+s; 
    }  
    for(int a=s.size()-1;a>=0;a--){
        if(s[a]!=x[a]){
            ans+=l;
        }
        if(a!=s.size()-1){
            l*=2;
        }
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==m){
            t++;
            la=0;
        }else{
            if(la==0){
                la=a[i];
            }else{
                la=yh(la,a[i]);
            }
            if(la==m){
                la=0;
                t++;
            }
        }
    }
    cout<<t;
    return 0;
}