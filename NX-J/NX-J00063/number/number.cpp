#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[1000000]={0};
    int a[1000000],q=0,n=0;
    cin>>s;
    for(int i=0;i<1000000;i++){
        if(s[i]!=0){
            q++;
        }
    }
    for(int i=0;i<q;i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            n++;
            a[i]=(int(s[i]))-48;
        }
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<q;j++){
            if(a[i]>=a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
