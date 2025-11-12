#include<bits/stdc++.h>
using namespace std;
string s;
int a[11],cnt;char ans[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]){
            ans[cnt++]=i+'0';
            a[i]--;
        }
    }
    if(ans[0]=='0'){
        cout<<0;
    }else{
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

