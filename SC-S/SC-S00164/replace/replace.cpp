#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+5;
pair<string,string> s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s[i]={s1,s2};
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0<<'\n';
			continue;
		}
		int l=0,r=t1.length()-1;
		while(l<t1.length()&&t1[l]==t2[l])l++;
		while(r>l&&t1[r]==t2[r])r--;
		int ans=0;
		for(int i=1;i<=n;i++){
			string s1=s[i].first,s2=s[i].second;
			int x1=t1.find(s1),x2=t2.find(s2);
			if(x1==-1||x2==-1||x1!=x2||x1>l||x1+s1.length()-1<r)
				continue;
			++ans;
		}
		cout<<ans<<'\n';
	}
	return 0;
}