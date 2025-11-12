#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int pop=0,visu=1,tot=0,n,ne,j=1,cnt,a[5010]={},vis[5010]={};

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n <= 6){

	if(n == 3){
		if(a[3]*2 < a[1]+a[2]+a[3]){
			cout<<1; 
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(n == 4){
		for(int i1 = 1;i1 <= n;i1++){
		for(int i2 = i1+1;i2 <= n;i2++){
		for(int i3 = i2+1;i3 <= n;i3++){
			if(a[i3] * 2 < a[i1]+a[i2]+a[i3]){
				cnt++;
				cnt %= MOD;
			}
		}
		}
		}
		
		for(int i = 1;i <= n;i++){
			tot += a[i];
		}
		if(a[4]*2 < tot){
			cnt++;
			cnt%=MOD;
		}
	}
	if(n == 5){
		for(int i1 = 1;i1 <= n;i1++){
		for(int i2 = i1+1;i2 <= n;i2++){
		for(int i3 = i2+1;i3 <= n;i3++){
			if(a[i3] * 2 < a[i1]+a[i2]+a[i3]){
				cnt++;
				cnt %= MOD;
			}
		}
		}
		}
		for(int i1 = 1;i1 <= n;i1++){
		for(int i2 = i1+1;i2 <= n;i2++){
		for(int i3 = i2+1;i3 <= n;i3++){
		for(int i4 = i3+1;i4 <= n;i4++){
			if(a[i4] * 2 < a[i1]+a[i2]+a[i3]+a[i4]){
				cnt++;
				cnt %= MOD;
			}
		}
		}
		}
		}
		for(int i = 1;i <= n;i++){
			tot += a[i];
		}
		if(a[5]*2 < tot){
			cnt++;
			cnt%=MOD;
		}
	}
	if(n == 6){
		for(int i1 = 1;i1 <= n;i1++){
		for(int i2 = i1+1;i2 <= n;i2++){
		for(int i3 = i2+1;i3 <= n;i3++){
			if(a[i3] * 2 < a[i1]+a[i2]+a[i3]){
				cnt++;
				cnt %= MOD;
			}
		}
		}
		}
		for(int i1 = 1;i1 <= n;i1++){
		for(int i2 = i1+1;i2 <= n;i2++){
		for(int i3 = i2+1;i3 <= n;i3++){
		for(int i4 = i3+1;i4 <= n;i4++){
			if(a[i4] * 2 < a[i1]+a[i2]+a[i3]+a[i4]){
				cnt++;
				cnt %= MOD;
			}
		}
		}
		}
		}
		for(int i1 = 1;i1 <= n;i1++){
		for(int i2 = i1+1;i2 <= n;i2++){
		for(int i3 = i2+1;i3 <= n;i3++){
		for(int i4 = i3+1;i4 <= n;i4++){
		for(int i5 = i4+1;i5 <= n;i5++){
			if(a[i5] * 2 < a[i1]+a[i2]+a[i3]+a[i4]+a[i5]){
				cnt++;
				cnt %= MOD;
			}
		}
		}
		}}
		}
		for(int i = 1;i <= n;i++){
			tot += a[i];
		}
		if(a[6]*2 < tot){
			cnt++;
			cnt%=MOD;
		}
	}
	cout<<cnt;
	return 0;
	}
	

	return 0;
}
