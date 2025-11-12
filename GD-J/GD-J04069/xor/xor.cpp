#include<bits/stdc++.h>
using namespace std;
fstream("xor.in","r",stdin);
fstream("xor.out","w",stdout);
int a[500005];
int n,k;
bool solve_xor(int l,int r){
	for(int i=l;i<=r;i++){
		int c=0;
		for(int j = i;j<=r;j++){
			c=c^a[j];
		}
		if(c==k){
			return true;
		}
	}
	return false;
}
int solve_0(){
	int c=0;
	for(int i = 1;i<=n;i++){
		if(a[i]==0){
			c++;
		}
		else if(a[i]==1&&a[i+1]==1){
			c++;
		}
	}
	return c;
}
int solve_1(){
	int c=0;
	for(int i = 1;i<=n;i++){
		if(a[i]==1){
			c++;
		}
	}
	return c;
}
int solve_0_1(){
	if(k==0)return solve_0();
	return solve_1();
}
int solve_255(){
	int l,r;
	int c=0;
	for(int i = 1;i<=n;i++){
		l=i;
		int c1=0;
		for(int j = i;j<=n;j++){
			r=j;
			if(solve_xor(l,r)){
				c1++;
				l=j+1;
			}
		}
		if(c1>c){
			c=c1;
		}
	}
	return c;
}
int main(){
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<solve_0_1();
	cout<<solve_255();
	return 0;
}
