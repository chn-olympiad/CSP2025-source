#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[10000];
    int c=0,d=0,f=0;
    char e;
    string s;
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[f]=s[i];
            f++;
        }
        else continue;
    }
    for(int i=0;i<=f-1;i++){
        for(int i=0;i<=f-1;i++){
            if(a[i]>c){
                c=a[i];
                d=i;
            }
        }
        e=char(c);
        cout<<e;
        a[d]=0;
        c=0;
    }

return 0;
}
