#include <bits/stdc++.h>
using namespace std;
bool cmp(int q1,int q2){
    return q1>=q2;
}
int top,a[1005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(;;){
        char q=getchar();
        if(q=='\n'){
            break;
        }
        if(q<='9'&&q>=0){
            top++;
            a[top]=q-'0';
        }
    }
    sort(a+1,a+1+top,cmp);
    for(int i=1;i<=top;i++){
        cout<<a[i];
    }
    return 0;
}
