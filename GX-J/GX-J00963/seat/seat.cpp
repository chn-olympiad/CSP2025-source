#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
int a[1000005],b[n][m];
for(int i=0;i<=n*m;i++){
    cin>>a[i];

}
for(int j=1;j<=n*m-1;j++){
    if(a[0]<a[j])n++;
    if(j%n>0)m++;
}
cout<<n<<m<<endl;

return 0;
}
