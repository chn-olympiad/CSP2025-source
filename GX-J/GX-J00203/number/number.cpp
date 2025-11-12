#include<bits/stdc++.h>
using namespace std;
int a[10000001];
string s,t;
int main(){

  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  for(int i=1;i<=10;i++){
  cin>>s[i];
    if(s[i]>='0'&&s[i]<='9'){
            if(s[i+1]>s[i]){
                    s[i]=t[i];
                s[i]=s[i+1];
            s[i+1]=t[i];

            }
        cout<<s[i];
    }
  }
return 0;
}
