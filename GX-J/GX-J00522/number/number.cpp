#include<bits/stdc++.h>
using namespace std;
int n[1000000],l=9,m[40],k;
string s;
void number(string s){
    int j=s.size();
    for(int i=0;i<j;i++){
        if(s[i]>='0'&&s[i]<='9'){
            k=s[i]-'0';
            m[k]++;
        }
        if(s[j]>='0'&&s[j]<='9'){
            k=s[j]-'0';
            m[k]++;
        }
    }
    while(l>=0){
        for(int i=0;i<m[l];i++){
            cout<<l;
        }
        l--;
    }
    return;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
  cin>>s;
  number(s);
    return 0;
}
