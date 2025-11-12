#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m,n,a[m*n],c;
cin>>m>>n>>c;
for(int i=1;i<=m*n;i++)
{
    cin>>a[i];
    if(a[i]<a[i+1])n++;
    if(c>n&&m%2==0)m++,n--;
    else m++,n++;
}
cout<<m<<' '<<n<<endl;
return 0;
}


