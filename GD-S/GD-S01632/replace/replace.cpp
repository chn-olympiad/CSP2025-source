#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q;
struct node{
	string s1,s2;
	bool operator <(const node&w)const{return s1<w.s1;}
}a[N];
set<node> st;
string t1,t2;
inline void solve1(){
	cin>>t1>>t2;
	int len=t1.size();
	int l=0;
	for(;l<len;l++){
		if(t1[l]!=t2[l]) break;
	}
	int r=len-1;
	for(;r>=0;r--){
		if(t1[r]!=t2[r]) break;
	}
	if(l>=r){
		cout<<"0\n";
		return;
	}
	string s1,s2;
	int ans=0;
	int rp=0;
	for(int i=l;i>=0;i--){
		for(int j=r;j<len;j++){
			if(++rp>=10000000/len){
				cout<<ans<<'\n';
				return;
			}
			s1=t1.substr(i,j-i+1);
			s2=t2.substr(i,j-i+1);
//			cout<<i<<'\n'; 
			ans+=(st.find({s1,s2})!=st.end());
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2,st.insert({a[i].s1,a[2].s2});
	while(q--){
		solve1();
	}
	return 0;
}
