#include <bits/stdc++.h>
using namespace std;
long long t,n,q[10000],flag;
char a[1000];
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>t>>n;
fgets(a,1000,stdin);
for(char* p=a-1;*p;p++){
    if(a[*p]==0){
        flag=1;
    }
}
for(int i=0;i<t;i++){
cin>>q[i];
}
long long sum=1;
if(flag==0){
for(int i=0;i<t;i++){
if(q[i]==0){
    t--;
}
}
for(int i=t;i>0;i--){
    sum*=i;
}
cout<<sum%998244353;
}
else{
    cout<<1;
}
return 0;
fclose(stdin);
fclose(stdout);
}
