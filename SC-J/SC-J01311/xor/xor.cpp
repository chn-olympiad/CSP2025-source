#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500010];
int b[500010];
bool is_A(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1) return 0;
	}
	return 1;
}
int A(){
	if(k==1){
		return n;
	}
	if(k==0){
		return n/2;
	}
	return 0;
}
bool is_B(){
	for(int i=1;i<=n;i++){
		if(a[i]>1) return 0;
	}
	return 1;
}
int B(){
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=a[i];
		}
		return cnt;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) b[i]=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			b[cnt]++;
		}
		else{
			b[++cnt]++;
		}
	}
	int ans=0;
	bool f=(a[1]==1); 
	for(int i=1;i<=cnt;i++){
		if(f){
			ans+=b[i]/2;
		}
		else ans+=b[i];
		f=~f;
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(is_A()){
		cout<<A();
		return 0;
	}
	if(is_B()){
		cout<<B();
		return 0;
	}
	return 0;
}