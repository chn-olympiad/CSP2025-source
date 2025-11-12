#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
long long k;
long long a[500005];
string er(long long x){
    string s="";
    while(x!=0){
        s+=(x%2)+'0';
        x/=2;
    }
    return s;
}
long long yh(string x,string y){
    string a=x,b=y,c="";
    if(a.size()!=b.size()){
        if(a.size()<b.size()){
            for(int i=1;i<=b.size()-a.size();i++){
                a="0"+a;
            }
        }else{
            for(int i=1;i<=a.size()-b.size();i++){
                b="0"+b;
            }
        }
    }
    for(int i=0;i<max(a.size(),b.size());i++){
        if(a[i]==b[i]){
            c+="0";
        }else{
            c+="1";
        }
    }
    long long q=0,p=0;
    for(int i=c.size()-1;i>=0;i--){
        long long t=pow(2,p++);
        q=q*10+t*(c[i]-'0');
    }
    return q;
}
long long sum,cnt;
bool nmflag;
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=0||a[i]!=1) nmflag=true;
    }
    if(k==0&&nmflag==false){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                sum++;
            }
            if(a[i]==1){
                cnt++;
            }
        }
        cout<<sum+cnt/2;
        return 0;
    }else if(k==1&&nmflag==false){
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                sum++;
            }
        }
        cout<<sum;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            cnt++;
            continue;
        }
        if(sum==0){
            sum=a[i];
        }else{
            sum=yh(er(sum),er(a[i]));
        }
        if(sum==k){
            cnt++;
            sum=0;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
