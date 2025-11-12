#include<bits/stdc++.h>
using namespace std;

char s[1000005];
int a[1000005],t=0;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++t]=s[i]-48;
        }
    }
    sort(a+1,a+t+1);
    for(int i=t;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
