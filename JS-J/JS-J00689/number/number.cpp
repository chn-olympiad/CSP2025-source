#include<bits/stdc++.h>
using namespace std;
int sum[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            sum[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(sum[i]==0){
            continue;
        }
        for(int j=0;j<sum[i];j++){
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
