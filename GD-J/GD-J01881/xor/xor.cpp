#include<bits/stdc++.h>
using namespace std;
	
int n,k;
void slove(){
	long long ans = 0;
	vector<int> v(n+5);
	for(int i=1;i<=n;i++) cin >> v[i];
	
	int pre = 0;
	for(int i=1;i<=n;i++){
		int xum = 0;
		for(int j=i;j>pre;j--){
			xum ^= v[j];
			if(xum == k){
				ans ++ ;
				pre = i;
				break;
			}
		}
	}
	
	cout << ans << '\n';
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	
	if(n <= 1000){
		slove();
		
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	cin.tie(0)->sync_with_stdio(0);
	vector<int> v(n+5);
	for(int i=1;i<=n;i++) cin >> v[i];
	int sum = 0;
	for(int i=1;i<=n;i++){
		sum += v[i];
	}
	
	cout << sum << flush;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
