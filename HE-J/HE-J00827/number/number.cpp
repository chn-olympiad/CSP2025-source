#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long a[11]={};
    cin>>s;
    long long q=s.size();
    for(long long i=0;i<q;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }for(long long i=9;i>=0;i--){
        for(long long j=1;j<=a[i];j++){
            cout<<i;
        }
    }return 0;
}
