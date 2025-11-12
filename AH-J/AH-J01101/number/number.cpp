#include<bits/stdc++.h>
using namespace std;
string b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    int n=s.size();
    int a[n+5]={};
    int cnt=0;
    int c[11]={};
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=s[i]-'0';
            for(int j=0;j<=9;j++){
                if(a[cnt]==j){
                    c[j]++;
                    break;
                }
            }
            cnt++;
        }
    }
    for(int i=9;i>=0;i--){
        while(c[i]){
            b+=i+'0';
            c[i]--;
        }
    }
    cout<<b<<endl;
    return 0;
}
