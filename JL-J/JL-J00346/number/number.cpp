#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int t[N],sl;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    sl=s.size();
    for(int i=0;i<sl;i++){
        if(s[i]>='0'&&s[i]<='9'){
            t[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(t[i]!=0){
            for(int j=1;j<=t[i];j++){
                printf("%d",i);
            }
        }
    }
    return 0;
}
