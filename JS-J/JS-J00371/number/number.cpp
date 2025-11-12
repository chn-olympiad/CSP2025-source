#include<bits/stdc++.h>
using namespace std;
long long num[12]={0};
long long n;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.length();
    for(long long i=0;i<n;i++){
        if(int(s[i])>=48&&int(s[i])<=57){
            num[int(s[i])-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        while(num[i]--){
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
