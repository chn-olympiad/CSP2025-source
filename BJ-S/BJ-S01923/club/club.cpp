#include<bits/stdc++.h>
using namespace std;
long long n;
int t;
struct node{
long long a1,a2,a3,cha1,cha2;
}a[100005];
bool cmp(node x,node y){
if(x.cha1==y.cha1){
    return x.cha2>y.cha2;
}else{
return x.cha1>y.cha1;
}
}
int main(){

  freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

cin>>t;
while(t--){
      long long  sum1=0,sum2=0,sum3=0,num=0;
cin>>n;
for(int i=1;i<=n;i++){
long long x,y,z;
    cin>>x>>y>>z;
    a[i].a1=x,a[i].a2=y,a[i].a3=z;
   if(x>=y&&y>=z){
   a[i].cha1=x-y,a[i].cha2=y-z;
   }else if(x>=z&&z>=y){
   a[i].cha1=x-z,a[i].cha2=z-y;
   }else if(y>=x&&x>=z){
   a[i].cha1=y-x,a[i].cha2=x-z;
   }else if(y>=z&&z>=x){
   a[i].cha1=y-z,a[i].cha2=z-x;
   }else if(z>=x&&x>=y){
   a[i].cha1=z-x,a[i].cha2=x-y;
   }else if(z>=y&&y>=x){
   a[i].cha1=z-y,a[i].cha2=y-x;
   }
}
sort(a+1,a+n+1,cmp);
for(int i=1;i<=n;i++){
    if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
        if(sum1<n/2){
            num+=a[i].a1;
            sum1++;
        }else if(a[i].a2>=a[i].a3){
            num+=a[i].a2;
            sum2++;
        }else{
            num+=a[i].a3;
            sum3++;
        }
    }else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
        if(sum2<n/2){
            num+=a[i].a2;
            sum2++;
        }else if(a[i].a1>=a[i].a3){
            num+=a[i].a1;
            sum1++;
        }else{
            num+=a[i].a3;
            sum3++;
        }
    }else{
        if(sum3<n/2){
            sum3++;
            num+=a[i].a3;
        }else if(a[i].a2>=a[i].a1){
            num+=a[i].a2;
            sum2++;
        }else{
            sum1++;
            num+=a[i].a1;
        }
    }
}
cout<<num<<endl;
}

return 0;
}
