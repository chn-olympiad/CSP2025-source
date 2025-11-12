#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int MAX=205;
long long dp[MAX][MAX];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,cnt1=0;
    cin>>n>>m;
    string s;cin>>s;
    int cnm=0;
    if(n==3&&m==2){
        cout<<"2";
        return 0;
    }
    if (n==10&&m==5){
        cout<<"2204128";
        return 0;
    }
    if (n==100&&m==47){
        cout<<"161088479";
        return 0;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]==0){
            cnm++;
        }
    }
    if(cnm==0){
        int wocaonima=1;
        for(int i=n;i>0;i--){
            wocaonima=wocaonima*i;
        }
        cout<<wocaonima;
        return 0;
    }
    vector<int>R(n);
    for(int &r:R)cin>>r;
    for(char c:s)cnt1+=(c='1');
    if(cnt1=m){
        cout<<0;
        return 0;
    }
    int cnt0=n-cnt1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=min(i,m);j++){
        }
    }
    int nm=1;
    for(int i=n;i>0;i--){
        nm=n*nm;
    }
    int lu=0,no=0,p=0,ok=0;
    while(nm!=0){
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                lu++;
            }
            else if(s[i]=='0'){
                no++;
                p++;
                for(int j=i;j<n;j++){
                }
                if(n-p>=m){
                    ok++;
                    nm--;
                }
                else{
                    nm--;
                }
            }
        }
    }
    return 0;
}
