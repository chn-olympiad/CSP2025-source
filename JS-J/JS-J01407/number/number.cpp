#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,a[15];
char t;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++){
       t=s[i];
       if(t>='0'&&t<='9'){
          a[t-'0']++;
       }
    }
    for(int i=9;i>=0;i--){
        while(a[i]){
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}
