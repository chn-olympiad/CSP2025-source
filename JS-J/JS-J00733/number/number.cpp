#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],tot,f;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++tot]=s[i]-'0';
            if(a[tot]!=0)f=1;
        }
    }
    sort(a+1,a+tot+1);
    if(f==0){
        cout<<0;
        exit(0);
    }
    for(int i=tot;i>=1;i--)cout<<a[i];
    return 0;
}
