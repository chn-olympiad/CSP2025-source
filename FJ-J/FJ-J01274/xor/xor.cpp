#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k,a[MAXN],s[MAXN],ans,rit;  //rit为当前所选的区间中的最右端点 
map<int,int> mp; 
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		
		int y=s[i]^k,tmp=mp[y];
		if ((tmp!=0 and rit<=tmp) or a[i]==k or (rit==0 and s[i]==k)/*特判第一次从s[1]开始*/){  //t!=0确保当前所求数存在，rit<=tmp确保区间不会重叠
			ans++;
			rit=i;
			//cout<<tmp+1<<' '<<i<<'\n'; 
		}
		
		mp[s[i]]=i;
	}
	//for (int i=1;i<=n;i++) cout<<s[i]<<' ';
	cout<<ans;
	return 0;
}

// s:2 3 3 0
// 第一次赛场做出第三题hh
// Happy+=INF; 
