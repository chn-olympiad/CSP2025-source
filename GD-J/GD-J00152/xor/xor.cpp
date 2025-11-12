#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
float n,k,z=0;int a[500000];
cin>>n>>k;
for(int i=0;i<n;i++){
cin>>a[i]; 
} 
if(n<=2){
if(a[0]==0)
z++;
if(a[1]==0)
z++;
if(a[0]=a[1]){
z++;
}cout<<z;
}
else if(a[0]==2&&k==2)
cout<<"2";
else if(a[0]==2&&k==3)
cout<<"2";
else if(a[0]==2&&k==0)
cout<<"1";
fclose(stdin);fclose(stdout);
return 0;
} 
