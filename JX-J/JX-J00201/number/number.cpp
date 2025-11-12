#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;

char s[1000005];
char a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int cnt=0;
    cin>>s;
    int l=strlen(s);
    sort(s,s+l);
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9') cnt++;
    }
    for(int i=0;i<cnt;i++){
        a[i]=s[i];
    }
    if(a[cnt-1]=='0') cout<<0;
    else{
        for(int i=cnt-1;i>=0;i--){
            cout<<a[i];
        }
    }
    return 0;
}
