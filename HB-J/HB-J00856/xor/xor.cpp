#include<bits/stdc++.h>
using namespace std;

freopen(xor.in,"r",std);
freopen(xor.out,"w",std);

int main(){
int n,k,i=0,s[500007],z[500007];
cin>>n>>k;
while(i-n){
i++;
cin>>s[i];
z[i]=s[i];
}
sort(z+1,z+n);
if(z[n]==1){
if(k==0){
cout<<n;
}else{
cout<<n/3;
}
}
return 0;
}
//#Shang4Shan3Ruo6Shui4
