#include<bits/stdc++.h>
using namespace std;
string s;
string a[100005];
int t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[t]=s[i];
            t++;
        }
    }
    sort(a,a+t);
    for(int i=t;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
