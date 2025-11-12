#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=4e5+5;
int n,q,ans;
struct P{
	int siz;
	string s1,s2;
	bool operator<(const P & nn)const{
		return siz<nn.siz;
	}
}a[N];
int dfs(string s1,string s2){
	if(s1==s2) ans++;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].siz=a[i].s1.size();
	}
	sort(a+1,a+n+1);
	while(q--){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		dfs(t1,t2);
		cout<<"0\n";
	}
	return 0;
}

