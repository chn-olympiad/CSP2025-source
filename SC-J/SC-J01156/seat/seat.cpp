#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int jb;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int t=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			jb=i;
		}
	}
	int a,b;
	if(jb%n==0){
		b=jb/n;
		cout<<b;
		if(b%2==0){
			cout<<" "<<1;
			return 0;
		} else{
			cout<<" "<<n;
			return 0;
		}
	}else{
		b=jb/n+1;
	}
	cout<<b;
	cout<<" ";
	if(b%2==0){
		cout<<n-(jb%n)+1;
	}else{
		cout<<1+(jb%n)-1;
	}
	return 0;
}