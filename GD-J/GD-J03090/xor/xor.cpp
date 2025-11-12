#include<bits/stdc++.h>
#define let long long


#define rt return
using namespace std;
let n,k,
	a,b,
	ans,
	mp[1000100],cnt[1000100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(let i = 1;i<=n;i++){
		cin>>mp[i];
		cnt[i] = cnt[i-1]^mp[i];
		if(mp[i] == 0)a++;
		if(mp[i] == 1)b++;
	}
	if(b == n){
		if(k == 0)ans = n/2;
		else if(k == 1) ans = n;
		cout<<ans;
		rt 0;
	}
	for(let i = 1,j = 1,sum = 0;j<=n;j++){
		sum^=mp[j];
		if(mp[j] == k){
			i = j+1;
			sum = 0;
			ans++;
			continue;
		}
		if(sum == k){
			
			i = j+1;
			sum = 0;
			ans++;
			continue;
		}else{
			let id = k^sum,f = 0;
			for(let x = i,sum_x = 0;x<j;x++){
				sum_x^=mp[x];
				if(sum_x == id){
					f = 1;
					break;
				}
			}
			if(f){
				i = j+1;
				sum = 0;
				ans++;
			}
			continue;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	rt 0;
}
