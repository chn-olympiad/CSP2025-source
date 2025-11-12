#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000009];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int cd=a.size();
    int o=0;
    for(int i=0;i<cd;i++){
        if(a[i]>='0'&&a[i]<='9'){
            o++;
            b[o]=a[i]-'0';
        }
    }
    sort(b+1,b+o+1);
    for(int i=o;i>0;i--){
        cout<<b[i];
    }
    return 0;
}
