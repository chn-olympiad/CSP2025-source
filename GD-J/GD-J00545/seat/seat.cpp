#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int a[100001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r1=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r1=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){

		if(a[i]==r1){
			r1=i;
		
			break;
		}
	}
	int u=r1/n;
	if(r1%n!=0){
		
		u++;
	}
	if(u%2==1){
		
		int k=(u-1)*n;
		int o=0;
		for(int i=1;i<=n*m;i++){
			if(r1==i+k){
				o=i;
			}
		}
		cout<<u<<" "<<o;
	}
	if(u%2==0){
		int k=(u-1)*n;
		int o=0;
		for(int i=1;i<=n*m;i++){
			if(r1==i+k){
				o=i;
			}
		}
		cout<<u<<" "<<n-o+1;
	}
	return 0;
}

