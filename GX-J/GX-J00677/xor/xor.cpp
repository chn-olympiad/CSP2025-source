#include<iostream>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool t=true,tp=true;
    long long n,k,p,sum=0;
    cin>>n>>k;
    long long s[n];
    cin>>s[0];
    if(s[0]!=1)t=false;
    if(s[0]!=0 && s[0]!=1)tp=false;
    else ++sum;
    for(int i=1;i<n;i++){
       cin>>p;
       s[i]=(s[i-1]^p);
       if(p!=1)t=false;
       else ++sum;
       if((p!=1)&&(p!=0)){
            tp=false;
       }
    }
    if(t){
            cout<<1;
            return 0;
    }
    if(tp){
        if(k==0)cout<<sum/2;
        if(k==1)cout<<sum;
    }
    return 0;
}
