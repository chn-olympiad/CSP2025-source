#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
int a[104],a1;
bool cmp(int a,int b){
return a>b;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++) cin>>a[i];
a1=a[1];
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=n*m;i++){
    if(a[i]==a1){
            a1=i;
    break;
    }
}
if(a1%n==0) cout<<a1/n<<" ";
else cout<<a1/n+1<<" ";
a1%=n;
if(a1==0) a1=m;
cout<<m-a1+1;
fclose(stdin);
fclose(stdout);
return 0;
}
