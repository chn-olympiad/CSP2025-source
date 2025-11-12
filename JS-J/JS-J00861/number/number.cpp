#include<bits/stdc++.h>
using namespace std;
string a;
string ans="";
int n[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int b=a.length();
    for(int i=0;i<b;i++){
        if(a[i]>='0'&&a[i]<='9'){
            n[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=n[i];j++){
            ans+=(i+'0');
        }
    }
    cout<<ans<<endl;
    return 0;
}
