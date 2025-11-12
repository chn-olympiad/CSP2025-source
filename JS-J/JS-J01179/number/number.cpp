#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string ch[N];
string ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int l=s.size();
    int cnt=0;
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            ch[++cnt]=s[i];
        }
    }
    sort(ch,ch+cnt+1);

    for(int i=cnt;i>=0;i--){
        ans+=ch[i];
    }
    cout<<ans<<endl;
    return 0;
}
