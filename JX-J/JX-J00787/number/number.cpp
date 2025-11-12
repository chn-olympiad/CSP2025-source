#include<bits/stdc++.h>
using namespace std;
int b[100020];
int n=0,num=0,c=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[100020];
    cin>>a;
    n=strlen(a);
    for(int i=0;i<=n;i++){
            c=0;
        if(a[i]>='0' && a[i]<='9'){
            num++;
            c=a[i]-'0';
            b[i]=c;
        }
    }
    sort(b,b+num);
    for(int i=num-1;i>=0;i--){
        cout<<b[i];
    }
    return 0;
}
