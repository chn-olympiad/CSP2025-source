#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cz=a[1];
	int id;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cz){
			id=i;
			break;
		}
	}
	bool fx;
	int s;
	if(id%n==0){
		s=id/n;
	}else{
		s=id/n+1;
	}
	if((s)%2==0){
		fx=1;
	}else{
		fx=0;
	}
	int ys=id%n;
	if(fx==1){
		cout<<s<<" ";
		if(ys==0){
			cout<<1;
		}else{
			cout<<n-ys+1;
		}
	}else{
		cout<<s<<" ";
		if(ys==0){
			cout<<n;
		}else{
			cout<<ys;
		}
	}
	return 0;
}