#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int cnt[15];
int read(){
    int f=1,g=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        g=g*10+ch-'0';
        ch=getchar();
    }
    return f*g;
}
void print(int x){
    if(x<0){
        putchar('-');
        x*=-1;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
    return;
}
main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9')cnt[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=cnt[i];j++)print(i);
    }
    // putchar('\n');
    return 0;
}