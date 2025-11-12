#include<bits/stdc++.h>
using namespace std;
string s;
int maxn=-1,num=0;
int main(){
    cin>>s;
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    for(int i=0;i< s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            if(s[i]>maxn){
                num=num*10+s[i];
            }
        }
    }
    cout<<num;
    return 0;
}
