#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s;
    while(cin>>s){
        if(s>='0'&&s<='9'){
            cnt++;
            a[cnt]=s-'0';
        }
    }
    sort(a+1,a+1+cnt);
    for(int i=cnt;i>=1;i--){
        printf("%d",a[i]);
    }
    return 0;
}
