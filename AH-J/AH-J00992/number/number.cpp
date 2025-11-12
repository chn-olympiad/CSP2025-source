#include<bits/stdc++.h>
using namespace std;
string s;
int l,i,t;
int p[1000060];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            t++;
            p[t]=s[i]-'0';
        }
    }
    sort(p+1,p+1+t);
    if(p[t]==0){
        cout<<0;
    }else{
        for(i=t;i>=1;i--){
            cout<<p[i];
        }
    }
    return 0;
}
//The key:#Shang4Shan3Ruo6Shui4
