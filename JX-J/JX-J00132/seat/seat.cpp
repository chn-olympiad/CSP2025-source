#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int x;
int l ;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.ans","w",stdout);
cin>>n>>m;
cin>>x;
for(int i=2;i<=n*m;i++){
    cin>>a[i];
    if(a[i]>x)l++;
}
l++;
if(l%n==0){
    cout<<l/n<<" "<<m;
    return 0;
}
cout<<(l/n)+1<<" "<<l%n;
return 0;
}
