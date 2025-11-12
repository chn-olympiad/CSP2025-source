#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int n,m,k,pay[11],h=k;
int a=m+n;
int u=0;
int l[i];
int r[10001];
int no[10001];
int ans;
for(int x=0;x<n;x++){
if(l[1]>l[3]>l[2])r[u]=l[2];
if(l[1]>l[2]>l[3])r[u]=l[3];
if(l[3]>l[2]>l[1])r[u]=l[1];
if(l[3]>l[1]>l[2])r[u]=l[2];
if(l[2]>l[1]>l[3])r[u]=l[3];
if(l[2]>l[3]>l[1])r[u]=l[1];
u++;
}
for(int y=0;y<k;y++){
for(int s=1;s<5;s++){
if(s==1){
pay[s]=l[3*m+s+1];
}
}
while(h!=0){
if(pay[s]>pay[s-1]){
ans=pay[s-1];
}
else{
ans=pay[s]
}
s--;
}
sort(r.begin,r.end());
for(int q=1;q<(r.size()/2);q++){
ans+=r[q];
}
}
return ans;
}
