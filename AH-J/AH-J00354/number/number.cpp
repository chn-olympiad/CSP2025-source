#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7;
string c;
int a[N];
int n;
signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>c;
for(int i=0;i<=c.size()-1;i++){
    if(c[i]>='0'&&c[i]<='9'){
        a[++n]=c[i]-'0';
    }
}
sort(a+1,a+n+1);
for(int i=n;i>=1;i--){
    cout<<a[i];
}
return 0;
}
