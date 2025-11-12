#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],k=0;
bool f(int x,int y){
    return x<y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=(s[i]-'0');
            k++;
        }
    }
    sort(a,a+k,f);
    for(int i=k-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
