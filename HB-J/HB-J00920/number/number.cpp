#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],cnt=0;
bool cmp(int x,int y){
    if(x!=y){
        return x>y;
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++cnt]=s[i];
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        cout<<a[i]-48;
    }
    return 0;
}
