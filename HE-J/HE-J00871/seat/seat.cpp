#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s;
bool cmp(int a,int b){
return a>b;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
cin>>a[i];
}
s=a[1];
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=n*m;i++){
if(a[i]==s){
s=i;
}
}
if(((s-1)/n)%2==1){
cout<<((s-1)/n)+1<<n-((s-1)%n);
}else{
if(s%n==0){
cout<<((s-1)/n)+1<<" "<<n<<endl;
}else{
cout<<((s-1)/n)+1<<" "<<s%n<<endl;
}
}
fclose(stdin);
fclose(stdout);
return 0;
}
