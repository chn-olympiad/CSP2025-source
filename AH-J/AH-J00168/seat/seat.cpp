#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1005],n,m;
bool cmp(long long A,long long B){
return A>B;	
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
cin>>a[i];
}
long long k=a[1];
//cout<<k;
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=n*m;i++){
if(a[i]==k){
k=i;
break;	
}	
}
//cout<<k;
long long h=(k-1)/n,e=(k-1)%n;
if((h+1)%2==1){
cout<<h+1<<' '<<e+1;
}
else{
cout<<h+1<<' '<<n-e;
}
return 0;
}
