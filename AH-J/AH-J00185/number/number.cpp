#include<bits/stdc++.h>

using namespace std;
int b[10];
string s,r;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            b[s[i]-'0']++;
        }
    }
    bool flag=false;
    for(int i=9;i>=0;i--){
        for(int j=1;j<=b[i];j++){
            r+=i+'0';
            if(i!=0){
                flag=true;
            }
        }
    }
    if(!flag){
        cout<<0;
    }else{
        cout<<r;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
