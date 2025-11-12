#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long a[100005]={0};
    long long s1=s.size(),o=0;
    if(s1==1){
        cout<<s[0];
    }else{
      for(int i=0;i<s1;++i){
        if(s[i]>='0'&&s[i]<='9'){
            a[o]=s[i]-'0';
            o++;
        }
      }
      sort(a,a+o,cmp);
      for(int i=0;i<o;++i){
        cout<<a[i];
      }
    }
    return 0;
}
