#include<bits/stdc++.h>
using namespace std;
int fx[4]={-1,1,0,0};
int fy[4]={0,0,-1,1};
int gcd(int a,int b){
    return (b>0?gcd(b,a%b):a);
}

int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie();cout.tie();
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]>0){
            a[i]--;
            cout<<i;
        }

    }
    return 0;
}
