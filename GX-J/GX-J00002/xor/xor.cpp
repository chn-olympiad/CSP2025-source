#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N],n,k,ans,x;
bool check(){
	for(int i = 1;i<=n;i++) 
		if(a[i] != 1) return 0;
	return 1;
}
bool check1(){
	for(int i = 1;i<=n;i++)
		if(a[i] != 1 && a[i] != 0) return 0;
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(check()){
		cout<<n/2;
		return 0;
	}
	if(check1()){
		int ans = 0;
		for(int i = 1;i<=n;i++) if(a[i])ans++;
		if(k==1){
			cout<<ans;
		}
		else{
			int num = 0;
			for(int i = 1;i<=n;i++) if(!a[i])num++;
			cout<<ans/2 + num;
		}
		return 0;
	}
	for(int i = 1;i<=n;i++){
		if(a[i] == 0) continue;
		x =  x ^ a[i];if(x == k)ans++,x=0;
	}
		cout<<ans;
	return 0;
}
