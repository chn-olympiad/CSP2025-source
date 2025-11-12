#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string a;
int sum,b[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[++sum]=int(a[i])-48;
        }
    }
    sort(b+1,b+sum+1);
    for(int i=sum;i>=1;i--){
        cout<<b[i];
    }
    return 0;
}
