#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long as[1000000]={0};
    long long x=0;
    long long n=s.size();
    if(n==1){
        cout<<s;
        return 0;
    }
    for(long long i=0;i<n;i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            as[++x]=s[i]-48;
        }
    }
    for(long long i=1;i<=x;i++){
        for(long long j=i+1;j<=x;j++){
            if(as[i]<as[j]){
                swap(as[i],as[j]);
            }
        }
    }
    for(long long i=1;i<=x;i++){
        cout<<as[i];
    }
    return 0;
}
