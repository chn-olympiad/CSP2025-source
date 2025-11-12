#include<bits/stdc++.h>
using namespace std;
int n,k,s,cnt,a[100005];
bool f=1;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]!=1){f=0;cnt++;}
    if(a[i]==1)s++;
}
if(f){
    cout<<n/2;
}
else if(k==1){
    cout<<s;
}
else{
    f=1;
    for(int i=1;i<=n;i++){
        if(a[i]==0)f=1;
        else if(f&&a[i]==1)f=0;
        else if(f==0&&a[i]==1)cnt++;
    }
    cout<<cnt;
}
return 0;
}
