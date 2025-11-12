#include<bits/stdc++.h>
using namespace std;
string a;
int n[1000005],cnt;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
for(int i=0;i<a.size();i++){
    if(a[i]>='0'&&a[i]<='9'){
        cnt++;
        n[cnt]=int(a[i])-48;
    }
}
sort(n+1,n+cnt+1);
if(n[cnt]==0){
    cout<<0;
    return 0;
}
for(int i=cnt;i>=1;i--){
    cout<<n[i];
}
}
