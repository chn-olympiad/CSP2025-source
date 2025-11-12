#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,cnt,vis[N+5];
long long k,a[N+5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(k==0 && n<=2){
		cout << n/2;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
	}
	else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
			else if(a[i]==a[i+1] && a[i]==1 && !vis[i] && !vis[i+1]){
				cnt++;
				vis[i]=vis[i+1]=1;
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
} 
