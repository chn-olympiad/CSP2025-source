#include<bits/stdc++.h>
using namespace std;
int t[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
            int shu=int(s[i]-'0');
            t[shu]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(t[i]>=1){
            while(t[i]>=1){
                cout<<i;
                t[i]--;
            }
        }

    }
    return 0;
}
