#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    int a[1000010],s=0;
    cin>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]>='0'&&n[i]<='9'){
            a[s]=n[i]-'0';
            s++;
        }
    }
    sort(a,a+s);
    if(a[s-1]==0){
        cout<<0;
        return 0;
    }
    for(int i=s-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
