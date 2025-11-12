#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100010];
int ans=0;
int f(int n,int a[],int sum){
	if (n==1){
		if (a[1]==k){
			ans++;
		}
	}else{
		int anst;
		for (int i=1;i<=sum+1-n;i++){
			anst=a[i];
			for (int j=i+1;j<=i+n-1;j++){
				anst=anst^a[j];
			}
			if (anst==k){
				ans++;
			}
		}
	}
}
void solve(){
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		f(i,a,n);
	}
	cout << ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
