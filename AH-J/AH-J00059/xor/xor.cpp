#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
string s[500001],s1,str;
string zh(long long n){
    if(n==0)return "0";
    string st="";
    while(n!=0){
        st+=(n%2)+'0';
        n/=2;
    }return st;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    s1=zh(m);
    //cout<<s1;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        s[i]=zh(a);
        //cout<<s[i]<<" ";
    }str=s[0];
    for(int i=1;i<=n;i++){
        if(str==s1){
            cnt++;
            str=s[i];
        }else{
            if(s[i].size()>str.size()){
                while(s[i].size()-str.size()>0)str+='0';
            }
            for(int j=0;j<str.size();j++){
                if(s[i][j]==str[j])str[j]='0';

                else str[j]='1';
            }
        }string s2=str,s3="";
        int f=0;
        for(int i=s2.size()-1;i>0;i--){
            if(s2[i]=='1')f=i;
        }for(int i=0;i<=f;i++)s3+=s2[i];
        str=s3;
        //cout<<str<<endl;
    }cout<<cnt;
    //290es1q0
    return 0;

}//#Shang4Shan3Ruo6Shui4
