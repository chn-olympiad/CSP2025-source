#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000010],ans;
long long two(long long a)
int i=0;
int b[100]={0};
long long c=0;
while(a>1){
    b[i]=a%2;
    a/=2;
    cout<<b[i]<<'/';
    i++;
}
b[i]=1;
for(int j=i;j>1;j--){
    c+=b[i]*pow(10,j);
}
if(b[0]==1){
    c+=1;
}
return c;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(k==0){
    cout<<n/2;
}
else if(k==1)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1){
            ans++;
        }
    }
    cout<<ans;
}
else{
    for(int i=0;i<=n;i++){
        if(a[i]==1){
        a[i]=two(a[i])
        cout<<a[i]<<endl;
        }
    }
}
return 0;
}
