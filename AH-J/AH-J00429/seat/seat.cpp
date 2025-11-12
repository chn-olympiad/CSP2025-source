#include<bits/stdc++.h>
using namespace std;
int a[101],b[13][13];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1],s;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(k==a[i]){
			s=i;
			break;
		}
	}
	if(m==1){
		cout<<1<<" ";
		if(n==1){
			cout<<s;
		}
		return 0;
	}
	else{
		cout<<s<<" "<<1;
		return 0;
	}
	if(n==2&&m==2){
		if(s==0){
			cout<<1<<" "<<1;
			return 0;
		}
		if(s==1){
			cout<<1<<" "<<2;
			return 0;
		}
		if(s==2){
			cout<<2<<" "<<2;
			return 0;
		}
		else{
			cout<<2<<" "<<1;
			return 0;
		}
	}
	if(s/n+1%2==1){
		cout<<(s-1)/n+1<<" "<<(s-1)%n+1;
	}
	else{
		cout<<(s-1)/n+1<<" "<<n-(s-1)%n+1;
	}
	return 0;
}
