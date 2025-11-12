#include<bits/stdc++.h>

using namespace std;

int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,m,k;
scanf("%d,%d,%d",&n,&m,&k);
int u[n],v[n],w[m],i=1,j=1;
for( ;i+1<=m;i++){
    scanf("%d,%d,%d",&u[i],&v[i],&w[i]);
}
int c[k],a[n];
    for( ;j+m+1<=k;j++){
    scanf("%d",&c[j]);
    for(int h=1;h<=n;h++){
    scanf("%d",&a[h]);
    }
}
int num=0,temp=1;
for(;j+m+1<=k;j++){
if(w[i]<w[i+1]){
    num=w[i];
}else if(w[i]==w[i+1]){
    num=w[i];
    temp++;
}else{
    num=w[i+1];
}
}
int mun=0,flag=1;
for( ;j+m+1<=k;j++){
if(c[j]<c[j+1]){
    mun=c[j];
}else if(c[j]==c[j+1]){
    mun=c[j];
    flag++;
}else{
    mun=c[j+1];
}
}
num=num*temp+mun*flag;
printf("%d",num);
fclose(stdin);
fclose(stdout);
return 0;
}
