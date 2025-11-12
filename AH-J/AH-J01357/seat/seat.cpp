#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
struct stu{
int s,p;
}a[101];
bool cmp(const stu &x,const stu &y){
return x.s>y.s;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)    cin>>a[i].s,a[i].p=i;
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=m;i++){
if(i%2)
for(int j=1;j<=n;j++){
cnt++;
if(a[cnt].p==1){
cout<<i<<' '<<j;
return 0;
}
}
else
for(int j=n;j>=1;j--){
cnt++;
if(a[cnt].p==1){
cout<<i<<' '<<j;
return 0;
}
}
}
return 0;
}
