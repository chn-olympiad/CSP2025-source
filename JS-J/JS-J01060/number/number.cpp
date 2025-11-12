#include <bits/stdc++.h>
using namespace std;
int v[1000005],x;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
                    v[x]=s[i]-'0';
                    x++;
            }
    }
    sort(v+0,v+x);
    for(int i=x-1;i>=0;i--)cout<<v[i];
    return 0;
}
