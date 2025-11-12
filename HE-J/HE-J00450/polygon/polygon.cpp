#include <bits/stdc++.h>
using namespace std;
int n,sssize;
long long sl[5002],sum;
vector<int> ss;
unsigned long long ans;
bool isA(vector<int> ss){
	long long sssum=0;
	for(int i=1;i<=sssize;i++){
		sssum += ss[i];
	}
	if(sssum>sum*2) return true;
	return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> sl[i];
		sum += sl[i];
	}
	sort(sl+1,sl+n+1);
	//¡êU€lc €€¡ê 
	for(int i=1;i<=n;i++){
		ss.clear();
		for(int j=3;j<=n;j++)
			ss.push_back(sl[j]);
//		if(!isA(ss)) break;
		ans++;
		if(ans>=998244353) ans %= 998244353;
	}
	if(ans%998244353==0) cout << n*2-1;
	cout << ans%998244353;
	return 0;
} 
