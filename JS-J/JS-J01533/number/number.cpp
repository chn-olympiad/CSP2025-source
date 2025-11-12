#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);//.out!!!
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]>='0'&&s[i]<='9'){
            int n=(s[i]-'0');
            a[n]++;
        }
    }
    for(int i=9;i>=0;--i){
        for(int j=0;j<a[i];++j){
            cout<<i;
        }
    }
    cout<<"\n";
    return 0;
}
