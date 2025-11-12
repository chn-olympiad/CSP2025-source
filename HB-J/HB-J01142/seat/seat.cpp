#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);

int n,m,peo;
peo=1;
cin>>n>>m;
int mr,j;
cin>>mr;
for(int i=2;i<=n*m;i++){
cin>>j;
    if(j>mr)peo++;
    }
    if(peo/n!=m)
    cout<<peo/n+1<<" ";
    else  cout<<peo/n<<" ";
if(peo/n%2==1)//go up
    cout<<m-peo%n;
    else
    cout<<peo%n;//go down
return 0;
}
