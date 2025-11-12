#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000001];
bool cmp(long long p,long long q){
	return p>q;
}
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin>>n>>m;
	long long s=0;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			s=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	long long mp=0;
	for(long long i=1;i<=n*m;i++){
		if(a[i]==s){
			mp=i;
			break;
		}
		
	}
	long long x;
	if(mp%n!=0){
		x=mp/n+1;
	}
	else{
		x=mp/n;
	}
	if(x%2==1){
		cout<<x<<" ";
		if(mp%n==0){
			cout<<n;
		}
		else{
			cout<<mp%n;
		}
		 
	}
	else{
		cout<<x<<" ";
		if(mp%n==0){
			cout<<1;
		}
		else{
			cout<<n-(mp%n)+1;
		}
	}
	return 0;
} 
