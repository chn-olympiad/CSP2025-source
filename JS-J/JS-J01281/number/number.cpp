#include<bits/stdc++.h>
using namespace std;
char a[1000007];
int l;
int b[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<=15;i++) b[i]=0;
    l=strlen(a);
    for(int i=0;i<l;i++){
        if('0'<=a[i]&&a[i]<='9'){
            int temp=a[i]-'0';
            b[temp]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=b[i];j++){
            printf("%d",i);
        }
    }
    return 0;
}
