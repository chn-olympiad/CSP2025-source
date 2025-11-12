#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000006];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int x=1;
    for(int i=0;i<s.size();i++){
        if(s[i] >='0' && s[i] <= '9'){
            n[x]=s[i]-'0';
            x++;
        }
    }
    sort(n+1,n+x+1);
    long long ans=0;
    for(int i=x;i>1;i--){
        printf("%d",n[i]);
    }
    return 0;
}
