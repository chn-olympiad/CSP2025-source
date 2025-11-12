#include<bits/stdc++.h>
using namespace std;
int shu[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int s1=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            shu[i]=s[i]-'0';
            s1++;
        }
    }
    sort(shu,shu+s.size());
    for(int i=s.size()-1;i>=s.size()-s1;i--){
        cout<<shu[i];
    }
    return 0;
}
