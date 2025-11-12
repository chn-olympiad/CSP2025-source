#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int num[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<=s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[s[i]-48]++;
        }
    }
    for(int i=10;i>=0;i--){

            for(int j=num[i];j>0;j--){
                if(j<=0){
                break;
                }
                cout<<i;
                num[i]--;
            }

    }
    return 0;
}
