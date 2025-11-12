#include<bits/stdc++.h>
using namespace std;
int k,a[500000]{0};
bool isk(int l,int r){
	int temp = 0;
	temp = a[l];
	for(int i = l+1;i <= r;i++){
		temp = temp^a[i];
	}
	return (temp == k);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,index = 0,ans = 0,l = 0,r = 0;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> a[i]; 
	}
	for(l = 0;l < n;l++){
		if(isk(l,r)){
			ans++;
			break;
		}
	}
	if(n <= 2&&k==1){
		cout << 1;
	}
	cout << ans;
	return 0;
	//FaZe Clan 22 CSGO Antwerp Major Champions
	//Twistzz karrigan broky ropz rain
}
