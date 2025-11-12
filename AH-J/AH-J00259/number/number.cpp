#include<bits/stdc++.h>
using namespace std;
string a,n[1000006];
int txt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            n[txt]=a[i];
            txt++;
        }
    }
    sort(n,n+txt);
    for(int i=txt;i>=0;i--){
        cout<<n[i];
    }
    return 0;
}
