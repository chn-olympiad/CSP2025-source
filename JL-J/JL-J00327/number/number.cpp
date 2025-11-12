#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int cnt=0,a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++cnt]=int(s[i]-'0');
        }
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
//0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx
