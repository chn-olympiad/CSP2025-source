#include<bits/stdc++.h>
using namespace std;
int n,k,a[600001];
int main(){
freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
cin >>n>>k;
for(int i=0;i<n;i++)cin>>a[i];
int cnt=0,sum=-1;
for(int j=0;j<n;j++)
{


for(int i=j;i<n;i++){
    if(sum==-1)sum=a[i];
    else sum=(sum|a[i])-(sum&a[i]);
    if(sum==k){


    cnt++,sum=-1,j=i+1;


    }
    //cout<<j<<" "<<i<<" "<<sum<<"\n";
}
}
cout<<cnt;



    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,k,a[100000];
int main(){
freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
cin >>n>>k;
for(int i=0;i<n;i++)cin>>a[i];
int cnt=0,sum=-1;
for(int j=0;j<n;j++)
{


for(int i=j;i<n;i++){
    if(sum==-1)sum=a[i];
    else sum=(sum|a[i])-(sum&a[i]);
    if(sum==k){


    cnt++,sum=-1,j=i+1;


    }
    //cout<<j<<" "<<i<<" "<<sum<<"\n";
}
}
cout<<cnt;



    return 0;
}
