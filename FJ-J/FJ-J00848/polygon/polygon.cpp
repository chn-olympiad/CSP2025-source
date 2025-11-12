#include<bits/stdc++.h>
//#define LOCAL_
using namespace std;
typedef long long ll;
const int mod = 998244353;

int n,cnt;
int a[5060],s[5060];
ll ans;

//i like bao_sou

vector<int>v;
ll sum(){
	int r = 0;
	for(int i : v){
		r+=i;
	}
	return r;
}

void dfs(int idx){
//	cout<<"inter:"<<cnt<<endl;
//	cnt++;
	if(a[idx]*2<sum()){
		ans++;
		ans%=mod;
	}
	if(idx == n){
		return ;
	}
	for(int i = idx+1;i<=n;i++)
	{
		v.push_back(a[i]);
		dfs(i);
		v.pop_back();
	}
	
}


int main()
{
#ifndef LOCAL_
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
#endif

	cin.tie(0)->sync_with_stdio(0);

	cin>>n;
	string s;
	getline(cin,s);
	stringstream ss(s);
	
	for(int i = 1;i<=n;i++){
		ss>>a[i];
		//cout<<"input:"<<i<<endl;
	}
	//cout<<"input end"<<endl;
	sort(a+1,a+n+1);
//	for(int i = 1;i<=n;i++){
//		s[i] = s[i-1]+a[i];
//	}
	
	dfs(0);
	cout<<ans<<endl;


	return 0;
}
