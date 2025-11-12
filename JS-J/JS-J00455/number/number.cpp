#include <bits/stdc++.h>
using namespace std;
string s;
string a[1000010];
bool cmp(string x,string y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='0'){
                a[i]=s[i];
        }
    }
    sort(a,a+len,cmp);
    for(int i=0;i<len;i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
