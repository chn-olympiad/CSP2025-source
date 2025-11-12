#include<bits/stdc++.h>
using namespace std;
const int N =1e5+20;
int f[N];
int x,y;

int yi(int m ,int n){
int ans = 0;
int a[10000],b[10000];
for(x = 1 ; m!=0 ; x++,m/=2)if(m%2==1)a[x]=1;else a[x] = 0;
for(y = 1 ; n!=0 ; y++,n/=2)if(n%2==1)b[y]=1;else b[y] = 0;

for(int i=1,p = 1;i<=max(x,y) ; i++,p*=2)if(a[i]!=b[i])ans+=p;
return ans;
}
int main(){
long long sum = 0 , maxn = -1;
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n , k;
cin>>n>>k;
for(int i = 1 ; i<= n ; i++)cin>>f[i];
int m = f[1];
for(int i = 1 ,j =1 ; i<= n ; i++){
   while(j<=i&&m!=k){
    j++;
    m=yi(m,f[j]);
   }
   if(m==k){sum++;m=f[i];}
}
cout<<sum<<endl;
return 0;
}
