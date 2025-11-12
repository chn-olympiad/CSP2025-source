#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500010],pre[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag_a = 1,flag_b = 1;
	int cnt_a = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i] != 1){
			flag_a = 0;
			if(a[i] != 0){
				flag_b = 0;
			}
		}
		else{
			cnt_a++;
		}
		pre[i] ^= pre[i-1];
	}
	int cnt_b = n - cnt_a;
	if(flag_a){
		if(k == 1){
			cout<<n;
		}
		else if(k == 0){
			cout<<n/2;
		}
		else{
			cout<<0;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(flag_b){
		if(k == 0){
			cout<<cnt_b + cnt_a / 2;
		}
		else if(k == 1){
			cout<<cnt_a + cnt_b / 2;
		}
		else{
			cout<<0;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//fucking CCF
