#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=5e5+5;

int n;
ll k,a[N],s[N];
map<ll,int> mp;

// 前缀异或、贪心
// 贪心：区间越短越好，记录当前 s[i]^k 的最晚出现位置
//       若找到一个可行的方案，则记录其右端点 r，下次
//		 若找到一个可行方案的左端点 l<=r，则排除
// 时间复杂度：O(n) 

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	ll ans=0,r=0;
	for(int i=1;i<=n;i++){
		ll need=s[i]^k;
//		cout<<"s["<<i<<"]需要"<<need<<endl;
		if(need==0&&1>r){
			r=i;
			ans++;
//			cout<<"["<<1<<","<<i<<"]"<<endl;
		}else if(mp.find(need)!=mp.end()&&mp[need]+1>r){
//			cout<<"["<<mp[need]+1<<","<<i<<"]"<<endl;
			r=i;
			ans++;
		}
		mp[s[i]]=i;
	}
	cout<<ans<<endl;
	return 0;
}

/*
4 0
2 1 0 3
01^11=10
*/

