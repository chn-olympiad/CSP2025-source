#include <bits/stdc++.h>
using namespace std;
int arr[105],temp[105];
int n,m,ans; 
void merge(long long ls,long long le,long long rs,long long re){
	int x=ls,flag=ls;
	while(ls<=le&&rs<=re){
		if(arr[ls]<arr[rs]) temp[x++]=arr[rs++];
		else temp[x++]=arr[ls++];
	}
	while(ls<=le) temp[x++]=arr[ls++];
	while(rs<=re) temp[x++]=arr[rs++];
	for(int i = flag;i<=re;i++) arr[i]=temp[i];
}
void sort_merge(long long l,long long r){
	if(l<r){
		int mid=(l+r)/2;
		sort_merge(l,mid);
		sort_merge(mid+1,r);
		merge(l,mid,mid+1,r);
	}
}
int main(){
	int x,y,f;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> arr[i];
	}
	ans=arr[1];
	sort_merge(1,n*m);
	x=1;y=n*m;
	for(int i = 1;i<=n*m;i++){
		if(arr[i]==ans) f=i;
	}
	int a=f/n+1,b;
	if((f/n+1)%2==1){
		b= f%n;
		if(b==0) b=m;
	}
	else{
		b= n-f%n+1; 
		if(b==0) b=1;
	}
	cout << a << ' ' << b;
	return 0;
} 
