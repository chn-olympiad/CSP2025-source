#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[1000006],h=1,k=1,k1=-1; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int d=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		h+=k;
		if(a[i]==d){
			cout<<ceil(i*1.0/n)<<' ';
			if(h%n==0||(h%n==1&&i!=1&&i%n==0))cout<<n;
			else cout<<h%n;
			return 0;
		} 
		if((h==n&&i%n==2)||(h==1&&i!=1)){
			swap(k,k1);
			h-=k;
		}
	}
	return 0;
}