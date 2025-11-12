#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[11]={0};
    string n;
    cin>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]>='0' && n[i]<='9') a[n[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(a[i]--) cout<<i;
    }
    return 0;
}
