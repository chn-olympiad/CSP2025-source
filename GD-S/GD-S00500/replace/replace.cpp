#include<bits/stdc++.h>
using namespace std;
long long n,q,z1[500005],z2[500005],p1,p2,ans;
string s1[500005],s2[500005],t1,t2;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
cin>>n>>q;
for(long long i=1;i<=n;i++){
cin>>s1[i]>>s2[i];
z1[i]=s1[i].find('b');
z2[i]=s2[i].find('b');
}
for(long long i=1;i<=q;i++){
cin>>t1>>t2;
ans=0;
p1=t1.find('b');
p2=t2.find('b');
for(long long j=1;j<=n;j++){
if(z2[j]-z1[j]==p2-p1 && s1[j].size()-z1[j]<=t1.size()-p1 && p1>=z1[j]){
ans++;
}
}
cout<<ans<<"\n";
}
return 0;
} 
