#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,k;
void solve1(){
	long long max=0;
	for(int i=1;i<=n;i++){
		max+=a[i];
	}
	cout<<max;
}
void solve2(){
	long long a1=0,a0=0;
	for(int i=1;i<=n;i++){
		if(a[i]) a1++;
		else a0++;
	}
	cout<<a1/2*2+a0/2*2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool flaga=true,flagb=true,flagc=true;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flaga=false;
		if(a[i]>1) flagb=false;
		if(a[i]>255) flagc=false;
	}
	if(flaga&&k==0){
		cout<<n/2*2;
		return 0;
	}
	if(flagb&&k<=1){
		if(k==1) solve1();
		else solve2();
	}
	return 0;
} 
