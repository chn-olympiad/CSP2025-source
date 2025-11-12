#include<bits/stdc++.h>
using namespace std;
int l;
int b[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            b[l]=s[i]-'0';
            l++;
        }
    }
    sort(b,b+l);
    for(int i=l-1;i>=0;i--){
        cout<<b[i];
    }
    return 0;
}

