#include<bits/stdc++.h>
using namespace std;
string s;
int num[10],k,len;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    for(int i=0;i<=9;i++){
        num[i]=0;
    }
    cin>>s;
    len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            k=int(s[i]-'0');
            num[k]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(num[i]>0){
            for(int j=1;j<=num[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
