#include<bits/stdc++.h>
using namespace std;

int n;
int lis[5010];
bool is_one = true;
long long ans = 0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>lis[i];
		if(lis[i] != 1){
			is_one = false;
		}
	}
	if(is_one){
		cout<<(n * (n-1) * (n-2)) / 6 % 998244353;
		return 0;
	}
	for(int i=7;i<=pow(2,n) - 1;i++){
		int ma = 0;
		int tot = 0;
		int num = 0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				num++;
				tot += lis[j];
				ma = max(ma,lis[j]);
			}
		}
		if(tot > ma * 2 && num >= 3){
			ans++;
		}
	}
	cout<<ans%998244353;
	return 0;
} 
