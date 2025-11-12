#include<bits/stdc++.h> 
using namespace std;
int a[5000],b[5000],c[5000],n,h,y=0;
int search(int h,int n){
if(h>3){
y++;
}
for(int i=0;i<n;i++){
if(h>2){
int o=0,mi=0;
if(!c[i]){
b[h]=a[i];
for(int j=1;j<=h;j++){
o+=b[j];
mi=max(b[j],mi);
cout<<o<<" "<<mi<<" "<<a[1-1]<<a[2-1]<<a[2]<<a[3]<<a[4]<<i<<endl;
}
if(mi*2<o){
c[i]=1;
search(h+1,n);
c[i]=0;
}
} 
}
else{
if(!c[i]){
b[h]=a[i];
c[i]=1;
search(h+1,n);
c[i]=0;
b[i]=0;
}
}
}
}
int main(){
freopen("polygon.in","r",stdin);	
freopen("polygon.out","w",stdout);	
cin>>n;
for(int i=0;i<n;i++){
cin>>a[i];
}		
search(1,n);
cout<<y;
fclose(stdin);	
fclose(stdout);	
return 0;
}



