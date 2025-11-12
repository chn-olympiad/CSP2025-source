#include<iostream>
#include<cstdio>
using namespace std;
string s;
long long b[20];
bool flag=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            b[s[i]-'0']++;
        }
    }
    for(long long i=9;i>=1;i--){
        if(b[i]) flag=1;
        while(b[i]--){
            printf("%d",i);
        }
    }
    if(flag){
        while(b[0]--){
            printf("0");
        }
    }else{
        printf("0");
    }
    fclose(stdin);
    fclose(stdin);
}
