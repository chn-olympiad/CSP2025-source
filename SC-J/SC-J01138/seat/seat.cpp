#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010]; 
int k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}
	if(k%n==0){
		if((k/n)%2==0){
			cout<<k/n<<" "<<1;
		}else{
			cout<<k/n<<" "<<n;
		}
	}else if((k/n)%2==0){
		cout<<k/n+1<<" "<<k%n;
	}else{
		cout<<k/n+1<<" "<<n-(k%n)+1;
	}
	return 0;
}