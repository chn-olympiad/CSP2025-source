#include<bits/stdc++.h>
using namespace std;
char a[1000000];
int b[1000000];
int main(){
    int q=0;
    for(int i=1;i<=strlen(a);i++){
        cin>>a;
        if(a[i]>='1'&&a[i]<='9'){
            b[q]=(a[i]-'0');
            q++;
        }
    }
    for(int i=1;i<=q;i++){
        cout<<b[i];
    }
    return 0;
    sort(b+1,b+q+1);
    for(int i=q;i>=1;i--){
        cout<<b[i];
    }
    return 0;
}
