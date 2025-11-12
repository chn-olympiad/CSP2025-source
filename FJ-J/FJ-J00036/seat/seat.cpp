#include<bits/stdc++.h>
using namespace std; 
long long n,m,s;
int a[200];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==r){
			s=i;
			break;
		}
	}
	if(s%n==0){
		if((s/n)%2==0) cout<<s/n<<" "<<1;
		if((s/n)%2!=0) cout<<s/n<<" "<<n;
	}
	if(s%n!=0){
		if((s/n)%2==0) cout<<s/n+1<<" "<<s%n;
		if((s/n)%2!=0) cout<<s/n+1<<" "<<n-s%n+1;
	}
	return 0;
}
