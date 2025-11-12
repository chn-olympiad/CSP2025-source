#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int num[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int sz=strlen(a);
    for(int i=0;i<sz;i++){
        if(a[i]>='0'&&a[i]<='9') num[a[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(num[i]){
            cout<<i;
            num[i]--;
        }
    }
    return 0;
}