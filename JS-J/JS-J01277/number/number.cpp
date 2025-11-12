#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
#define ll long long
int a[maxn];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k=1;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[k]=int(s[i]-'0');
            k++;
        }
    }
    sort(a+1,a+k);
    if(a[k-1]==0)cout<<0;
    else{
        for(int i=k-1;i>=1;i--){
        cout<<a[i];
        }
    }
    return 0;
}
