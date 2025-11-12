#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
}
int t=a[1];
int t1;
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=n*m;i++){
	if(a[i]==t){
	t1=i;
	break;	
	} 
}int v;
if(t1%n==0)
v=t1/n;
else
v=t1/n+1;
cout<<v<<" ";
if(v%2==0){
	cout<<(n+1)-((t1-1)%n+1);
}else{
	cout<<(t1-1)%n+1;
}
}
