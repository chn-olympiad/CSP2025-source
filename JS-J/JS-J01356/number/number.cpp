#include<bits/stdc++.h>
using namespace std;
const int maN=1e6+5;
char s[maN];
int a[10],n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    n=strlen(s);
    for(int i=0;i<n;i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]){
            cout<<i;
            a[i]--;
        }
    }
}
