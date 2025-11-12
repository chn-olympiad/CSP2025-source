#include<bits/stdc++.h>
using namespace std;
int yh(int a,int b){
if(a==b) return a;
int ans=0;
int c=1;
while(a||b){
    int x=0;
    int y=0;
    x=a&1;
    y=b&1;
    if(x==1||y==1){
        ans+=c;
    }
    a=a>>1;
    b=b>>1;
    c*=2;
}
return ans;
}
struct oo{
 int h;
 int t;
 };
int cmp(const oo&a,const oo&b){
if(a.t>b.t) return a.t<b.t;
if(a.t<b.t) return a.t>b.t;
if(a.h>b.h) return a.h<b.h;
return a.h>b.h;
}

int main(){
    freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);


int n,k;
cin>>n>>k;
int a[n+1];
for(int i=1;i<=n;i++){
    cin>>a[i];
}

for(int i=1;i<=n;i++){
    //cout<<a[i]<<endl;
}
int l=1;
struct oo an[n*n];
for(int i=1;i<=n;i++){
        int sum=a[i];
        //cout<<sum<<endl;
    for(int j=i;j<=n;j++){
         //   cout<<sum<<endl;
         sum=yh(sum,a[j]);
   // c[i][j]=sum;
   // cout<<i<<' '<<j<<' '<<sum<<endl;
    if(sum==k){
        an[l].h=i;
        an[l].t=j;
        l++;
    }
    }
 //   cout<<endl;
}
sort(an+1,an+l+1,cmp);
int ans=0;
int ch1=n+1;
for(int i=l;i>0;i--){
    if(ch1>an[i].t){
        ans++;
        ch1=an[i].h;
      //  cout<<an[i].h<<an[i].t;
    }
}

cout<<ans;
}
