#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
struct Node{
	string s_1="",s_2="";
	int a=0,b=0;
	int len;
}node[200001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	vector<int> k;
	vector<int> s;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>node[i].s_1>>node[i].s_2;
		for(auto j:node[i].s_1){
			if(j=='b')break;
			node[i].a++;
		}for(auto j:node[i].s_2){
			if(j=='b')break;
			node[i].b++;
		}
		k.push_back(node[i].a-node[i].b);
		s.push_back(node[i].s_1.size());
	}
	while(q--){
		string t_1,t_2;
		cin>>t_1>>t_2;
		int a=0,b=0,len=0,s_now;
		for(auto i:t_1){
			if(i=='b')break;
			a++;
		}for(auto i:t_2){
			if(i=='b')break;
			b++;
		}
		len=a-b;
		s_now=t_1.size();
		int s_now1=t_2.size();
		if(s_now!=s_now1){
			cout<<0<<"\n";
			continue;
		}
		int ans=0,num=0;
		for(int i=0;i<n;i++){
			num++;
			if(s[i]>s_now)continue;
			if(num>n)break;
			if(k[i]==len)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
