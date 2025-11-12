#include<bits/stdc++.h>
using namespace std;
string a;
int b[10005];
int j=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<10005;i++){
        if(a[i]>=48&&a[i]<=58){
            j++;
            b[j]=a[i]-48;
        }
    }
    sort(b+1,b+j+1);
    for(;j>=1;j--){
       printf("%d",b[j]);
    }
    return 0;
}

