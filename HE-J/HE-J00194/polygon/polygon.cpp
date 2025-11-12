#include<bits/stdc++.h>
using namespace std;
int n;
int main (){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;

int a[n];
for(int i=0;i<n;i++){
cin>>a[i];
}
int ans=0,maxx=a[0];
for(int i=0;i<n;i++){
ans+=a[i];
if(a[i]>maxx)
maxx=a[i];
}
cout<<ans<<maxx*2<<endl;
if(n<3)
cout<<0;
else if(n=3){
if(ans>maxx*2)
cout<<1;
else cout<<0;
}

else{


int cnt=1;
for(int i=n-1;i>=0;i--){
if(a[i]==maxx)
continue;
else{
ans-=a[i];
if(ans>maxx*2){
cnt++;
}
ans+=a[i];
}
}
cout<<cnt;


}
fclose(stdin);
fclose(stdout);
return 0;
}
