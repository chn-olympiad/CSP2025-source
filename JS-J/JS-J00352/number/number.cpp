#include<bits/stdc++.h>
using namespace std;
int ans[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int j=1;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans[j]=s[i]-'0';
            j++;
        }
    }
    sort(ans+1,ans+j+1);
    for(int i=j;i>1;i--){
        cout<<ans[i];
    }
    return 0;
}
