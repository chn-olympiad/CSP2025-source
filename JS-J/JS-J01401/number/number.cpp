#include <bits/stdc++.h>

using namespace std;
int read();
void write(int x);
string s;int a[20];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<10;i++) a[i]=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++) putchar(i+'0');
    }
    return 0;
}
int read(){
    int x,y=1;char c;
    while((c=getchar())>'9'||c<'0') if(c=='-') y=-1;
    x=(c^48);
    while ((c=getchar())>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48);
    return x*y;
}
void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
