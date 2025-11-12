#include<bits/stdc++.h>
using namespace std;
struct Po{
long long aa;
long long bb;
long long cc;
}a[100005];
struct op{
long long zz;
long long id;
}b[5];
long long t,n,z[5],ans;
bool cmp(Po a,Po b){
long long q1=max(max(a.aa,a.bb),a.cc),q2=min(min(a.aa,a.bb),a.cc),q3=a.aa+a.bb+a.cc-q1-q2;
long long p1=max(max(b.aa,b.bb),b.cc),p2=min(min(b.aa,b.bb),b.cc),p3=b.aa+b.bb+b.cc-p1-p2;
if(q1-q3!=p1-p3){
return q1-q3>p1-p3;
}
return q3-q2>p3-p2;
}
bool ncmp(op a,op b){
return a.zz>b.zz;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
while(t--){
ans=0;
cin>>n;
z[1]=z[2]=z[3]=0;
for(long long i=1;i<=n;i++){
cin>>a[i].aa>>a[i].bb>>a[i].cc;
}
sort(a+1,a+1+n,cmp);
for(long long i=1;i<=n;i++){
b[1].zz=a[i].aa,b[1].id=1;
b[2].zz=a[i].bb,b[2].id=2;
b[3].zz=a[i].cc,b[3].id=3;
sort(b+1,b+4,ncmp);
if(z[b[1].id]<n/2){
z[b[1].id]++;
ans+=b[1].zz;
}
else if(z[b[2].id]<n/2){
z[b[2].id]++;
ans+=b[2].zz;
}
else{
z[b[3].id]++;
ans+=b[3].zz;
}
}
cout<<ans<<"\n";
}
return 0;
} 
