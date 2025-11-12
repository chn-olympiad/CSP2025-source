#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[100005];
long long l;
int sum;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.ans","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==k){
        sum++;
        continue;
    }
    l^=a[i];
    if(l==k){
        sum++;
        l=0;
    }
    cout<<l<<endl;
}
cout<<sum;
return 0;
}
