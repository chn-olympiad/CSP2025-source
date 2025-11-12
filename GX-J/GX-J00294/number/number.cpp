#include<bits/stdc++.h>
using namespace std;
int a[1000005],t;
char c[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>c;
    for(int i=0;i<strlen(c);i++){
        if(c[i]>='0'&&c[i]<='9'){
            a[t]=c[i]-'0';
            t++;
        }
    }
    sort(a,a+t);
    for(int i=t-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
