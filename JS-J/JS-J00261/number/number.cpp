#include<bits/stdc++.h>
using namespace std;
int s[1111111],j=0;
string p;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>p;
    for(int i=0;i<p.length();i++){
        if(p[i]>='0'&&p[i]<='9'){
            s[j]=p[i]-'0';
            j++;
        }
    }
    sort(s,s+j);
    for(int i=j-1;i>=0;i--){
        cout<<s[i];
    }
    return 0;
}
