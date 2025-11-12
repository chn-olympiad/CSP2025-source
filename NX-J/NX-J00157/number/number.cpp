#include <bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,m;
    cin>>s;
    for(int i=0;i<=s.length();i++){
        if(s[i]-'0'<10){
          m[a]=s[i];
          a=a+1;
        }

    }

    for(int i=0;i<=a;i++){
        for(int j=0;j<=a;j++){
            if(m[j]<m[i]){
                b=m[j];
                c=m[i];
                m[i]=b;
                m[j]=c;
            }
        }
    }
    for(int  i=0;i<=a;i++){
        cout<<m[i];
    }

    return 0;
}
