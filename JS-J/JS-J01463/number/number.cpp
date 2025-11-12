#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=strlen(s);
    int num=0;
    for(int i=0;i<=n;i++){
        if('0'<=s[i]&&'9'>=s[i]){
            a[++num]=s[i]-'0';
        }
    }
    sort(a+1,a+num+1);
    for(int i=num;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
