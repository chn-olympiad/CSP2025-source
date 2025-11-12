#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,P=1e7;
int n,q,p[N];
struct node{
	int sz,p,h;
};
vector<node> num[20000010];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int l,r,pa,ha;
		cin>>s1;
		cin>>s2;
		for(int i=0;i<s1.size();i++){
			if(s1[i]=='b'){
				l=i;
				pa=l,ha=s1.size()-l-1;
			}
			if(s2[i]=='b'){
				r=i;
			}
		}
		num[r-l+P].push_back(node{s1.size(),pa,ha});
	}
	while(q--){
		int l,r,pa,ha;
		cin>>s1;
		cin>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<s1.size();i++){
			if(s1[i]=='b'){
				l=i;
				pa=l,ha=s1.size()-l-1;
			}
			if(s2[i]=='b'){
				r=i;
			}
		}
		int ans=0;
		for(auto v:num[r-l+P]){
			int x=v.sz,y=v.p,z=v.h;
			if(x<=s1.size()&&pa>=y&&ha>=z) ans++;
		}
		cout<<ans<<"\n";
	}
}
