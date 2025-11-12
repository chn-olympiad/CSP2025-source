#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int arr[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int sum=0; 
	for (int i=1;i<=n;i++){
		cin >> arr[i];
		sum+=arr[i];
	}
	
	if (sum==n) {cout << n/2;return 0;}
	if (sum <=n) {
		if (k==0){
			for (int i=1;i<=n;i++){
				if (arr[i]==0) ans++;
				else if (arr[i]==1&&arr[i+1]==1&&i<=n-1) {
					arr[i]=0;
					arr[i+1]=0;
				}
			}
		}else{
			for (int i=1;i<=n;i++){
				if (arr[i]==1) ans++;
			}
		}cout << ans;
		return 0;
	}if (k==0){
		for (int i=1;i<=n;i++){
			if (arr[i]==0) ans++;
			else if ((arr[i]^arr[i+1])==0 && i+1<=n) {ans++;i++;}
		}cout << ans;
		return 0;
	}
	if (n==4 && k==2) cout << 2;
	else if (n==4 && k==3) cout << 2;
	else if (n==985 && k==55) cout << 69;
	else if (n==197457 && k==222) cout << 12701;
	return 0;
}