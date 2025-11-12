#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int ans[1000005]={},p=0;
    cin>>a;
    int x;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            ans[p]=a[i]-'0';
            p++;
        }
    }
    sort(ans,ans+p);
    for(int i=p-1;i>=0;i--){
        cout<<ans[i];
    }

    return 0;
}
