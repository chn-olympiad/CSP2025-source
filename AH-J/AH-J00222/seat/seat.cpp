#include<bits/stdc++.h>
using namespace std;
long long n,mm,nn;
struct node{
    long long pos,fs;
}a[105];
bool cmp(node x,node y){
     return x.fs>y.fs;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld %lld",&nn,&mm);
    for(long long i=1;i<=nn*mm;i++){
        a[i].pos=i;
        scanf("%lld",&a[i].fs);
    }
    sort(a+1,a+nn*mm+1,cmp);
    long long ans=0;
    for(long long i=1;i<=nn*mm;i++){
        if(a[i].pos==1){
            ans=i;
        }
    }
    long long l=ans/mm,r=ans%mm;
    if(r==0){
       if(l%2==1){
           cout<<l<<" "<<nn;
       }else{
           cout<<l<<" "<<1;
       }
    }else{
       l++;
       r--;
       if(l%2==1){
          cout<<l<<" "<<r+1;
       }else{
          cout<<l<<" "<<nn-r;
       }
    }
    return 0;
}
