#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll=long long;

const int mod=998244323;
bool cmp(int a,int b){
	return a>b;
}
int n;
vector<int> s(n+8);

void solve1(){
	if(s[0]>=s[1]+s[2]) cout<<0;
	else cout<<1;
	return;
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s.begin(),s.begin()+n,cmp);
	if(n<=3){
		solve1();
	}else cout<<n/2*76;
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	solve();
	return 0;
} 
