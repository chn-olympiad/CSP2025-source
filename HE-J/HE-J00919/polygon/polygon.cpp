#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,a[5001],sum=0,num=0;
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i];
}
for(int i=1;i<=n;i++){
    if(a[i]+a[i+1]+a[i+2]>2*a[i+2]&&a[i+2]!=0){
        sum++;
    }
    if(a[i]+a[i+1]+a[i+2]+a[i+3]>2*a[i+3]&&a[i+3]!=0){
        sum++;
    }
    if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>2*a[i+4] &&a[i+4]!=0 ){
        sum++;
    }
    if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]>2*a[i+5]&&a[i+5]!=0){
        sum++;
    }
    if(a[i]+a[i+2]+a[i+3]>2*a[i+3]&&a[i+3]!=0){
        sum++;
    }
    if(a[i]+a[i+2]+a[i+3]+a[i+4]>2*a[i+4]&&a[i+4]!=0){
        sum++;
    }
    if(a[i]+a[i+2]+a[i+3]+a[i+4]+a[i+5]>2*a[i+5]&&a[i+5]!=0){
        sum++;
    }
    if(a[i]+a[i+3]+a[i+4]>2*a[i+4]&&a[i+4]!=0){
        sum++;
    }
    if(a[i]+a[i+3]+a[i+4]+a[i+5]>2*a[i+5]&&a[i+5]!=0){
        sum++;
    }
    if(a[i]+a[i+4]+a[i+5]>2*a[i+5]&&a[i+5]!=0){
        sum++;
    }

}
cout<<sum;
fclose(stdin);
fclose(stdout);

return 0;
}

