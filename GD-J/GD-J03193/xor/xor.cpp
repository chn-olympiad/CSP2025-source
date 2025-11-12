#include<bits/stdc++.h>
using namespace std;
string fun(string a,string b){
    int i,n=max(a.size(),b.size());
    string c;
    while(a.size()>b.size()){
        b="0"+b;
    }
    while(b.size()>a.size()){
        a="0"+a;
    }
    for(i=0;i<n;i++){
        c=c+char((a[i]!=b[i])+'0');
    }
    while(c[0]=='0'){
        c=c.substr(1);
    }
    return c;
}
string bin(int n){
    string s;
    while(n>0){
        s=char(n%2+'0')+s;
        n/=2;
    }
    return s;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    if(n<=2){
        if(n==1){
            printf("0");
        }else{
            printf("1");
        }
    }else{

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
