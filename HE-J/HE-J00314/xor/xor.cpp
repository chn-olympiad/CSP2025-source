#include <bits/stdc++.h>
using namespace std;
int nu[500006];int n,k;int ans,axb;

bool check(int tk){
	int a = nu[1],answer=0;bool isc=true;
	axb = 1;
	for(int i = 1;i<=n;i++){
		if(a==k) {
			answer++;
			//cout << axb << " could " << i << endl;
			a = nu[i+1];axb = i+1;
		}
		else {
			if(axb != i){
				a ^= nu[i];
				//cout << "yihuo:" << nu[i] << "geted:" << a << endl;
			}
			//cout << axb << " " << i << endl;
		}
	}
	if(a==k)answer++;
	return answer>=tk;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> nu[i];
	}
	int l = 1,r = n+1,mid=0;
	while(l<=r){
		mid = (l+r)/2;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
} 
