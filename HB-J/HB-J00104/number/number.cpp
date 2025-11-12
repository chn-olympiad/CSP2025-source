#include<bits/stdc++.h>
#define For(i,a,b)for(int i=a;i<=b;i++)
using namespace std;
const long long N=1e6+10;
string s;
int a[N];
bool cmp(const int& a,const int& b){
    return a>=b;
}
inline int read(void){
    register int x=0,f=1;
    register char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            f=-f;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x<=9){
        putchar(x+'0');
        return;
    }else{
        write(x/10);
        putchar(x%10+'0');
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int sum=0;
    For(i,0,s.size()-1){
        if(s[i]>='0'&&s[i]<='9'){
            sum++;
            a[sum]=(int)(s[i]-'0');
        }
    }
    sort(a+1,a+1+sum,cmp);
    For(i,1,sum) write(a[i]);
    return 0;
}
