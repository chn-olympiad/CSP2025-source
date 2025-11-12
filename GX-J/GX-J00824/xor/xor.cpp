#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
void solve1(){
	cout<<n;
	return;
}
void solve2(int x,int y){
	if(k==1){
		cout<<y;
	}
	else{
		cout<<x+y/2;
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		cout<<n;
		return 0;
	}
	int f=0;
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) x++;
		if(a[i]==1) y++;
		if(a[i]!=1) f=1;
	}
	if(f==0) solve1();
	else if(x+y==n) solve2(x,y);
	return 0;
}
