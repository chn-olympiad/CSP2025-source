#include<bits/stdc++.h>
using namespace std;
int a[50],n,t[50],ans=0;

void pd(){
	int sum=0,r=0,ma=0;
	for(int i = 0;i < n;i++){
		sum+=t[i];
		if(t[i]!=0)r++;
		ma=max(ma,t[i]);
	}
	//for(int i = 0;i < n;i++){
	//	cout << t[i] << " ";
	//}cout << endl;
	if(r>=3&&sum>ma*2){
		ans++;
		ans=ans%988244353;
	}
	return;
} 

void dfs(int k){
	//cout << k;
	if(k==n){
		pd();
		return;
	} else {
		t[k]=0;
		dfs(k+1);
		t[k]=a[k];
		dfs(k+1);
		t[k]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >>a[i]; 
	}
	dfs(0);
	cout << ans;
} 
