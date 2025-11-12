#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int yh(long long a,long long b){
    long long len1=0,len2=0;
    string x="",y="",j="";
    while(a!=0){
        x+=(a%2);
        a/=2;
        len1++;
    }
    while(b!=0){
        y+=b%2;
        b/=2;
        len2++;
    }
    if(x=="") x+='0';
    if(y=="") y+='0';
    long long len3=max(len1,len2);
    for(int i=0;i<len3;i++){
        if(x[i]!=y[i]) j+='1';
        else j+='0';
    }
    long long c=1,jg=0;
    for(int i=0;i<len3;i++){
        jg+=c*(j[i]-'0');
        c*=2;
    }
    return jg;
}
long long n,k,a[N],s1,s2,f;
bool v[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1) s1++;
    }
    if(k==0){
        for(long long i=0;i<n;i++){
            if(a[i]==0) s2++;
            else if(a[i]!=0&&a[i-1]!=0&&a[i]==a[i-1]) s2++;
        }
        cout<<s2;
    }
    else if(k==1) cout<<s1;
    else {
        for(int i=0;i<n;i++){
            if(v[i]) continue;
            int s=0;
            for(int j=i;j<n;j++){
                if(s!=0) s=yh(s,a[j]);
                else s=a[j];
                if(s==k){
                    f++;
                    v[j]=1;
                    break;
                }
            }
        }
        cout<<f;
    }

    return 0;

}
