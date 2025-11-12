#include<bits/stdc++.h>
using namespace std;
int num[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[s[i]-'0']++;
       }
    }
    string ans="";
    for(int i=9;i>=0;i--){
        while(num[i]>0){
            ans+=i+'0';
            num[i]--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
