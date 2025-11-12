#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
bool cmp(int x,int y){
return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=n*m;
	for(int i=0;i<p;++i){
		cin>>a[i];
	}
	int k=a[0];
	sort(a,a+p,cmp);
	for(int i=0;i<p;++i){
	if(a[i]==k){
	k=i+1;
	break;
	}
}
int x;
if(k%n==0)
x=k/n;
else
x=k/n+1;
int y;
if(x%2==0){
	y=n-k%n+1;
}
else {
	if(k%n==0)
	y=n;
	else
	y=k%n;
}
cout<<x<<" "<<y;
return 0;
}
