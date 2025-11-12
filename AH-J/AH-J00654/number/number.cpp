#include<bits/stdc++.h>
using namespace std;
int s[1000005],cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            s[++cnt]=a[i]-48;
        }
    }
    sort(s+1,s+1+cnt);
    if(s[cnt]==0){
        cout<<0;
        return 0;
    }
    for(int i=cnt;i>=1;i--){
        cout<<s[i];
    }

    return 0;
}
