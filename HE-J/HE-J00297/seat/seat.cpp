#include<bits/stdc++.h>
using namespace std;
int a[1000];
int R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,r;
	cin>>n>>m;
	cin>>r;
	a[r]++;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		a[x]++;
	}
	for(int i=100;i>=1;i--){
		if(a[i]!=0){
			R++;
			if(i==r){
				i=0;
			}
		}
	}
	int s=R/n;
	int y=R-s*n;
	if(R%n==0){
		cout<<s<<" ";
	}else{
		cout<<s+1<<" ";
	}
	if(R%n==0){
		if((s+1)%2==0){
			cout<<n;
		}else{
			cout<<1;
		}
	}else{
		if((s+1)%2==0){
			cout<<n-y+1;
		}else{
			cout<<y;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
