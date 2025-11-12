#include<bits/stdc++.h>
using namespace std;
int a[1005];
string to_two(int x){
    string s;
    while(x){
        char ch=(char)((x%2)+48);
        s=ch+s;
        x/=2;
    }
    return s;
}
string XOR(int a,int b){
    string a1=to_two(a);
    string b1=to_two(b);
    string s="";
    if(a1.size()>=b1.size()){
        for(int i=1;i<=a1.size()-b1.size();i++){
            b1='0'+b1;
        }
    }
    else{
        for(int i=1;i<=b1.size()-a1.size();i++){
            a1='0'+a1;
        }
    }
    for(int i=a1.size()-1;i>=0;i--){
        if(a1[i]!=b1[i]){
            s='1'+s;
        }
        else{
            s='0'+s;
        }
    }
    return s;
}
int to_ten(string s){
    int sum=0,pow=1;
    for(int i=s.size()-1;i>=0;i--){
        sum+=(s[i]-48)*pow;
        pow*=2;
    }
    return sum;
}
int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s=0,cnt=1;
    while(cnt<=n){
        int t=0;
        for(int i=cnt;i<=n;i++){
            if(a[i]==k){
                t++;
                continue;
            }
            int sum=a[i];
            for(int j=i+1;j<=n;j++){
                sum=to_ten(XOR(sum,a[j]));
                if(sum==k){
                    t++;
                    i=j;
                    break;
                }
            }
        }
        s=max(s,t);
        cnt++;
    }
    cout<<s;

    return 0;
}
