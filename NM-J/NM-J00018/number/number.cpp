#include<bits/stdc++.h>
using namespace std;
string s;
int a[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]-'0'<=9&&s[i]-'0'>=0){
            a[s[i]-'0']++;
        }
    }
    //for(int i=1;i<=9;i++) cout<<a[i]<<" ";
    for(int i=9;i>=0;i--) {
        while (a[i]>=1){
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}