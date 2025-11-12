#include<iostream>
using namespace std;
string s;
int b[15],a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            b[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(i==0&&a==0){
            cout<<0;
            break;
        }else{
            a+=b[i];
            for(int j=1;j<=b[i];j++){
                cout<<i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
