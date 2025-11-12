#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int a[1000001];
int k[1000001];
int f=1,d=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",&s);
    for(int i=0;i<=100;i++){
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
            a[f]=s[i]-'0';
            f++;
        }
    }
    sort(a+1,a+1+f);
    d=f;
    for(int i=1;i<f;i++){
        k[i]=a[d];
        d--;
    }
    for(int i=1;i<f;i++){
        cout<<k[i];
    }
    return 0;
}
