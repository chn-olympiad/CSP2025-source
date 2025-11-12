#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
string s1,s2;
int lens;
}s[200010];
string t1,t2;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
cin>>n>>q;
for(int i=1;i<=n;i++){
cin>>s[i].s1>>s[i].s2;
s[i].lens=s[i].s1.size();
}
int lent,ans;
while(q--){
cin>>t1>>t2;
if(t1.size()!=t2.size()){
    cout<<0<<endl;
    continue;
}
ans=0;
lent=t1.size();
for(int i=1;i<=n;i++){
if(s[i].lens>lent)continue;
int x=t1.find(s[i].s1);
if(x==-1)continue;
int y=t2.find(s[i].s2);
if(y!=x)continue;
bool flag=1;
for(int j=0;j<lent;j++){
    if(j==x){
        j+=s[i].lens;
    }
    if(t1[j]!=t2[j]){
        flag=0;
        break;
    }
}
if(flag)ans++;
}
printf("%d",ans);
cout<<endl;
}
return 0;}
