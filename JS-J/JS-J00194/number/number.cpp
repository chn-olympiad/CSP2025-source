#include<bits/stdc++.h>
using namespace std;
void fff(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
}
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
string s;
int a[1000005],n;
int cnt[10];
int main(){
    fff();
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a[++n]=s[i]-'0';
    }
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=n;i++){
       write(a[i]);
    }
    puts("");
    return 0;
}
