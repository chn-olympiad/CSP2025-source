#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int w=a[1],id=0;
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==w){
			id=i;
			break;
		}
	}
	
	int l=(id/n)+(id%n?1:0);
	
	if(l%2==1){
	//	return 0;
		if(id%n!=0){
			cout<<l<<" "<<(id%n);
		}
		else{
			cout<<l<<" "<<n;
		}
	//	return 0;
	}
	else{
	//	return 0;
		cout<<l<<" "<<(n-(id%n)+1);
	//	return 0;
	}
	return 0;
}
