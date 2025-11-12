#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
	}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int x;
cin>>x;
a[1]=x;
for(int i=2;i<=n*m;i++){
cin>>a[i];
}
sort(a+1,a+n*m+1,cmp);
int w;
for(int i=1;i<=n*m;i++){
if(a[i]==x){
w=i;
break;
}
}
int c,r;
c=(ceil)(w*1.0/n);
if(c%2==0){
r=n-(w-(c-1)*n)+1;
}else{
r=w-(c-1)*n;
}
cout<<c<<' '<<r;
return 0;
}
