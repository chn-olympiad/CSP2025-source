#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1);
    bool ok=0;
    for(int i=cnt;i>=1;i--){
        if(a[i]==0&&!ok){
            continue;
        }
        ok=1;
        cout<<a[i];
    }
    if(!ok) cout<<0;
    return 0;
}
