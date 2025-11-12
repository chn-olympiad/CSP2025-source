#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e6+10;

int n,q,now,now2;
int tree[N][30];
int tree2[N][30];
int cnt[N],cnt2[N];
void build(string s1,string s2){
	int u=0;
	for(int i=0;i<s1.size();i++){
		if(!tree[u][s1[i]-'a']) tree[u][s1[i]-'a']=++now;
		if(i==s1.size()-1) cnt[now]++;
		u=now;
	}
	u=0;
	for(int i=0;i<s2.size();i++){
		if(!tree2[u][s2[i]-'a']) tree2[u][s2[i]-'a']=++now2;
		if(i==s2.size()-1) cnt2[now2]++;
		u=now2;
	}
	return;
}

int query(string s1,string s2){
	int l,r,ans=0,u;
	for(l=0;s1[l]==s2[l];l++){
	}
	for(r=s1.size()-1;s1[r]==s2[r];r--){
	}
	for(int j=0;j<=l;j++){
//		cout<<j<<"\n";
		u=0;
		for(int i=j;i<s1.size();i++){
//			cout<<u<<" "<<tree[u][s1[i]-'a']<<" "<<tree2[u][s2[i]-'a']<<"\n";
			if(tree[u][s1[i]-'a']!=tree2[u][s2[i]-'a']||tree[u][s1[i]-'a']==0)break;
			if(i>=r){
				ans+=cnt[tree[u][s1[i]-'a']];
			}
			u=tree[u][s1[i]-'a'];
		}
	}
	return ans;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),std::cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		build(s1,s2);
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<query(s1,s2)<<"\n";
	}
	return 0;
}
