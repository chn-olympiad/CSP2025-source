#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int p=1;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[p]=s[i]-'0';
            p++;
        }
    }
    for(int i=0;i<p-1;i++){
        for(int j=0;j<p-1;j++){
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
        }
    }
    for(int i=p-1;i>0;i--){
        cout<<a[i];
    }
    return 0;
}
