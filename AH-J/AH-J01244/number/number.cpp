#include<iostream>
using namespace std;
string s;
int t[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            t[int(s[i]-'0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        while(t[i]>0){
            cout<<i;
            t[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
