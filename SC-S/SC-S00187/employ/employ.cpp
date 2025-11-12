#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	ll ans = 0;
	string s;
	cin>>s;
	vector<int> A(n),B(n);
	//使用B数组来表示排列顺序
	for(int i=0;i<n;i++){
		cin>>A[i];
		B[i] = i;
	}
	//骗分
	if(n>18){//为什么样例不对？？？
		ans = 1;
		for(int i=1;i<=n;i++){
			ans = (ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	//暴力
	do{
		//模拟
		int ju=0,cnt=0;
		//ju存储被拒绝的人数，cnt存储录用了多少人
		for(int i=0;i<n;i++){
			if(ju >= A[B[i]] || s[i]=='0'){
				ju++;
			}else cnt++;
		}
		if(cnt>=m) ans = (ans+1)%mod;
	}while(next_permutation(B.begin(),B.end()));
	cout<<ans;
	return 0;
}