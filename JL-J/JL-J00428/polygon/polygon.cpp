#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5001];
long long ans=0;
void dd(long long y,long long maxx,long long h,long long x){
if(x>n)
    return;

if(maxx*2<h&&y>=3&&x==n){
        cout<<h<<" "<<maxx<<" "<<y<<endl;
        ans++;

}dd(y+1,a[y+1],h+a[y+1],x+1);
dd(y,maxx,h,x+1);

}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);

cin>>n;
for(long long i=1;i<=n;i++ ){
    cin>>a[i];
}
sort(a+1,a+n+1);
dd(0,0,0,0);
cout<<ans;
return 0;

}
