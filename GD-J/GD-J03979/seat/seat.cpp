#include<bits/stdc++.h>
using namespace std;
long long a[1000];
void cct(long long n,long long m,int p){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cout<<p<<" ";
	if(p%n==0){
		if((p/n)%2==0){
			cout<<1<<" "<<p/n;
		}
		else cout<<n<<" "<<p/n;
	}
	else{
		if((p/n+1)%2 == 1) cout<<p%n<<" "<<p/n+1;
		else cout<<n-p%n+1<<" "<<p/n+1;
	}
}
bool cmp(long long a,long long b){
	if(a<b) return false;
	else return true;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,v;
	cin>>n>>m;
	cin>>a[0];
	v=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(&a[0],&a[n*m+1],cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==v){
			cct(n,m,i+1);
			break;
		}
	}
}
