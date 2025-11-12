#include <bits/stdc++.h>
using namespace std;
int len,ans[10000005],lop;
string s;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    lop=0;
    for(int i=0;i<len;i++){
        if(s[i]<='9'&&s[i]>='0'){
            ans[lop]=s[i]-'0';
            lop++;
        }
    }

    sort(ans,ans+lop,cmp);
    for(int i=0;i<lop;i++){
        cout<<ans[i];
    }
    //cout<<endl;
    //system(diff "number.out" "number2.ans");
    return 0;
}
