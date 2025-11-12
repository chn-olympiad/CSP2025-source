#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int mp[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",&s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9')mp[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=mp[i];j++)printf("%d",i);
    }
    return 0;
}
