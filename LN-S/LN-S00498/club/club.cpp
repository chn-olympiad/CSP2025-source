#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int i,n,t,j;
struct member{
int a;
int b;
int c;
int fail1;
int fail2;
};
member  p[100005];
int club1[100005],club2[100005],club3[100005];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
for(j=0;j<t;j++){
cin>>n;

for(i=1;i<=n;i++){
    cin>>p[i].a;
    cin>>p[i].b;
    cin>>p[i].c;
}
int x(0),y(0),z(0),ans(0);
for(i=1;i<=n;i++){
if((p[i].a>=p[i].b)&&(p[i].a>=p[i].c)){
    club1[i]=p[i].a;x++;ans+=p[i].a;
    p[i].fail1=p[i].a-p[i].b;
    p[i].fail2=p[i].a-p[i].c;
}
if((p[i].b>p[i].c)&&(p[i].b>p[i].a)){
    club2[i]=p[i].b;y++;ans+=p[i].b;
    p[i].fail1=p[i].b-p[i].a;
    p[i].fail2=p[i].b-p[i].c;
}
if((p[i].c>p[i].a)&&(p[i].c>p[i].b)){
    club3[i]=p[i].c;z++;ans+=p[i].c;
    p[i].fail1=p[i].c-p[i].a;
    p[i].fail2=p[i].c-p[i].b;
}
}
for(i=1;i<=n;i++){
    ans+=max({p[i].a,p[i].b,p[i].c});
}
if((x<=n/2)&&(y<=n/2)&&(z<=n/2)){
cout<<ans<<endl;continue;
}
int d(100005),e(100005);
while(x>n/2){

for(i=1;i<=n;i++){

    if(d>p[i].fail1){
        d=i;
    }
    if(e>p[i].fail2){
        e=i;
    }
}
if(p[d].fail1<=p[e].fail2){
   if(y+1<=n/2){
    x--;y++;ans-=p[d].fail1;
}
    else if(x>n/2){
        x--;z++;ans-=p[d].fail2;
    }
}
else if(z+1<=n/2){
    x--;z++;ans-=p[e].fail2;
}
    else{
        x--;y++;ans-=p[e].fail1;
    }
    p[d].fail1=100005;
    p[e].fail2=100005;
}
while(y>n/2){

for(i=1;i<=n;i++){

    if(d>p[i].fail1){
        d=i;
    }
    if(e>p[i].fail2){
        e=i;
    }
}
if(p[d].fail1<=p[e].fail2){
   if(x+1<=n/2){
    y--;x++;ans-=p[d].fail1;
}
    else if(y>n/2){
        y--;x++;ans-=p[d].fail2;
    }
}
else if(z+1<=n/2){
    y--;z++;ans-=p[e].fail2;
}
    else if(y>n/2){
        y--;x++;ans-=p[e].fail1;
    }
}
while(z>n/2){

for(i=1;i<=n;i++){

    if(d>p[i].fail1){
        d=i;
    }
    if(e>p[i].fail2){
        e=i;
    }
}
if(p[d].fail1<=p[e].fail2){
   if(x+1<=n/2){
    z--;x++;ans-=p[d].fail1;
}
    else if(z>n/2){
        z--;y++;ans-=p[d].fail2;
    }
}
else if(y+1<=n/2){
    z--;y++;ans-=p[e].fail2;
}
    else if(z>n/2){
        z--;x++;ans-=p[e].fail1;
    }
}
cout<<ans<<endl;
}

return 0;
}
