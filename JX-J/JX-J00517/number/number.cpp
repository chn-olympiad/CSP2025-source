#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    char c[100010];
    for(long i=0;i<=s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
         c[i]=s[i];
    }
    for(long i=0;i<s.size();i++){
        for(long j=i+1;j<s.size();j++){
            if(c[j]>c[i]){
                char ch=c[j];
                c[j]=c[i];
                c[i]=ch;
            }
        }
    }
    for(long i=0;i<s.size();i++){
        cout<<c[i];
    }
    return 0;
}
