#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
if(x>y)return 1;
else return 0;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
int t=a[1];
sort(a+1,a+1+n*m,cmp);
for(int i=1;i<=n*m;i++){
    if(a[i]==t)t=i;
}
if(t%n==0){
    if(t/n%2!=0)cout<<t/n<<" "<<n;
    else cout<<t/n<<" "<<1;
}
else if(t/n%2!=0)cout<<t/n+1<<" "<<n-(t-t/n*n)+1;
else cout<<t/n+1<<" "<<t-t/n*n;
return 0;
}
