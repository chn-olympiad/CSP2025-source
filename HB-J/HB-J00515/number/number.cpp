#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+50;

template<class T>
inline T read(){
    T x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
string s;
char c[N];
ll cnt=0;
bool cmp(char x,char y){
    return x>y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(ll i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            c[++cnt]=s[i];
        }
    }
    sort(c+1,c+cnt+1,cmp);
    for(ll i=1;i<=cnt;i++){
        cout<<c[i];
    }cout<<endl;
    return 0;
}
