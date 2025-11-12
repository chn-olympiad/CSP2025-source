#include<bits/stdc++.h>
using namespace std;
long long n,m,l;
long long a[1001];
bool cmp(long long a,long long b){
return a>b;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(long long i=1;i<=n*m;i++){
    cin>>a[i];

} l=a[1];
sort(a+1,a+n*m+1,cmp);
long long h=1;long long kk=0;
for(long long i=1;i<=m;i++){
        if(i%2==1){
              for(long long j=1;j<=n;j++){
                    kk++;

         if(a[kk]==l){
        cout<<i<<" "<<j;
        return 0;}

       }
        }

else{

    for(long long j=n;j>=1;j--){
            kk++;
         if(a[kk]==l){
        cout<<i<<" "<<j;
        return 0;}
       }
}
}

return 0;
}
