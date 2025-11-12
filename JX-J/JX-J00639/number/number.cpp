#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[25];
string o;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>o;
    for(int i=0;i<o.size();i++){
        if(o[i]>='0'&&o[i]<='9'){
            a[int(o[i]-'0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }

    return 0;
}
