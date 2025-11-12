#include<bits/stdc++.h>
using namespace std;
int b[15],n;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        char x=s[i];
        if('0'<=x&&x<='9')b[x-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(b[i]--)cout<<i;
    }
    return 0;
}
