#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int num[10],i;
char str[maxn];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>str[i]){
        if('0'<=str[i]&&str[i]<='9')
            num[str[i]-'0']++;
    }
    bool flag=0;
    for(int i=9;i>=0;i--){
        if(num[i]&&(i||flag&&!i)){
            flag=1;
            cout<<string(num[i],i+'0');
        }
    }
    return 0;
}
