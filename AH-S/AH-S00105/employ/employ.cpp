#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,m,b,c,d,e,he[100005][5];
bool f[100005];
struct node{
long long v,jd,id,ve,vr;
}a[500005];
string s;
bool cmp(node A,node B){
if(A.v!=B.v)return A.v>B.v;
else return max(A.ve,A.vr)<max(B.ve,B.vr);
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m>>s;
d=n;
for(int i=1;i<=m;i++){
cin>>b;
if(b==0)d--;
}
c=1;
for(int i=1;i<=d;i++){
c*=i;
c%=998244353;
}

cout<<c;
return 0;
}
