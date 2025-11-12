#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a;
int g=-1,dep=0;
void p(int x,int y){
if(x>=y){
return;
}
int m=a[x];
int i;
for(i=x+1;i<y;i++){
m=m^a[i];
if(m==k||a[i]==k){
dep++;
g=max(g,dep);
}
p(i+1,y);
dep=0;
}
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1,x;i<=n;i++){
cin>>x;
a.push_back(x);
}
int o=a.size();
p(0,n);
cout<<g;
return 0;
}
