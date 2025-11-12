#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    char c[1010];
    int n=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            c[n++]=s[i];
    }
    int len=strlen(c);
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(c[i]<=c[j]){
                char t=c[i];
                c[i]=c[j];
                c[j]=t;
            }
        }
    }
    for(int i=0;i<len;i++)cout<<c[i];
    return 0;
}
