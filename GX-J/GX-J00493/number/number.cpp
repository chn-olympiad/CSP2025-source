#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int b[10010];
    int z=0;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if('0'==a[i]||'1'==a[i]||'2'==a[i]||'3'==a[i]||'4'==a[i]||'5'==a[i]||'6'==a[i]||'7'==a[i]||'8'==a[i]||'9'==a[i]){
            b[z]=a[i];
            z++;
        }
    }
    sort(b+0,b+z);
    for(int i=z;i>=0;i--) cout<<char(b[i]);
    return 0;
}
