#include "cstdio"

int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int a[10000],t,n,d[3]={0},sum=0,max=0;
scanf("%d",&t);
for(int i=0;i<t;i++){
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++ ){
if((a[i]>a[j])&&(d[1]!=(n/2))){
a[j]=a[i];
d[1]++;
sum+=a[i]
}else{
break;
}
if((a[i]>a[j])&&(d[2]!=(n/2))){
a[j]=a[i];
d[2]++;
sum+=a[i]
}else{
break;
}
if((a[i]>a[j])&&(d[3]!=(n/2))){
a[j]=a[i];
d[3]++;
sum+=a[i]
}else{
break;
}
}
}
if(sum>max){
    max=sum;
}
else{
  printf("%d",max);
}
}
return 0;
}
