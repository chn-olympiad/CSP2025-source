#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r=0;
	cin>>n>>m;
	int s1=n*m+1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(n*m==1){
			cout<<1<<' '<<1;
			return 0;
		}
	}
	
	r=a[1];
	int num=0;
	sort(a+1,a+s1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			num=i;
			break;
		}
	}
	int ha=0;
	if(num%n==0){
		ha=num/n;
	}
	else{
		ha=num/n+1;
	}
	if(n==1){
		cout<<num<<' '<<n;
	}
	else if(ha%2==0){
		cout<<ha<<' '<<n-(num%n)+1;
	}
	else{
		if(num%n==0){
			cout<<ha<<' '<<n;
		}
		else{
			cout<<ha<<' '<<num%n;
		}
	}
	return 0;
}
