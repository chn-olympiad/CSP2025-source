#include <bits/stdc++.h>
using namespace std;
char c;
int a[1000005],cnt=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>c){
        if(c>='0'&&c<='9'){
            cnt++;
            a[cnt]=c-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        cout<<a[i];
    }
    return 0;
}
