#include<bits/stdc++.h>
using namespace std;
string ch;
int a[91],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>ch;
    for(int i=0;i<ch.size();i++){
        if(ch[i]>='0'&&ch[i]<='9') a[++cnt]=(ch[i]-'0');
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--) cout<<a[i];
    return 0;
}
