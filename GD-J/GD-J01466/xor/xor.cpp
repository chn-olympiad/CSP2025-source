#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	
	int n,k;
	cin >> n >> k;
	int N[500005]={0};
	for(int i=1;i<=n;i++){
		cin >> N[i];
	}
	//cout << (1^1);
	if(n <= 2){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(N[i] == 0){
				ans++;
			}
		}
		cout << ans;
		return 0;
	}
	if(k == 0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(N[i] == 0){
				ans++;
			}
			else if(N[i] == N[i+1]){
				ans++;
				i++;
			}
		}
		cout << ans;
		return 0;
	}
	if(k=1){
		int ans=0;
		for(int i=2;i<=n;i++){
			if(N[i-1]+1 == N[i]){
				ans++;
				i++;
			}
			else if(N[i-1]-1 == N[i]){
				ans++;
				i++;
			}
		}
		cout << ans;
		return 0;
	}
	
	return 0;
}
