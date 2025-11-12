#include<iostream>
#include<cstdio>
using namespace std;
int num[10]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9')
            num[s[i]-'0']++;
    }
    int if_0=0;
    for(int i=9;i>=0;i--){
        if(i>=1){
            if(num[i]>0){
                for(int j=0;j<num[i];j++){
                    cout<<i;
                }
            }
            else{
                if_0++;
            }
        }
        else{
            if(if_0==9){
                cout<<0;
            }
            else{
                for(int j=0;j<num[i];j++){
                    cout<<0;
                }
            }
        }
    }
    return 0;
}
