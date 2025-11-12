#include<iostream>
#include<string>
using namespace std;
string s;
long long a[10]={};
int main(){
    freopen("number.out","w",stdout);
    freopen("number.in","r",stdin);
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(long long i=9;i>=0;i--){
        for(long long j=0;j<a[i];j++){
            printf("%lld",i);
        }
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}
