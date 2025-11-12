#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int n1,int n2){
	return n1>n2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
		x=a[1];
	}
	if(n==1 && m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(a[i]==x){
		int w=i/n;
		if(i==n) {
			cout<<1<<" "<<n;
			return 0;
		}
		if(i==n+1) {
			cout<<2<<" "<<n;
			return 0;
		}
		if(i%n==0) cout<<w<<" "<<1;
		if(i%n!=0) {
			if((w+1)%2==0) cout<<w+1<<" "<<n-i%n+1;
			if((w+1)%2!=0) cout<<w+1<<" "<<i%n;
		}
		}
	}
	return 0;
}
//2 5 4 6 7 1 3 9 8 16 12 14 15 11 13 10
//11 5 4 6 7 1 3 9 8 16 12 14 15 2 13 10
