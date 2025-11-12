#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    int a[1000005];
    int m=0;
    for(int i=0;i<=n.size()-1;i++){
        if(n[i]>='0'&&n[i]<='9'){
            a[++m]=n[i]-'0';
        }
    }
    sort(a+1,a+m+1);
    for(int i=m;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
