#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int x=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            x++;
            a[x]=int(s[i]-'0');
        }
    }
    sort(a+1,a+x+1);
    for(int i=x;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
