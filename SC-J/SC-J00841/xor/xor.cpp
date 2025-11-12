#include<bits/stdc++.h>
using namespace std;
struct S{
	int a,b;
};
vector<S> v;
map<int,int> ma;
int n,m,s[500005];
bool cmp(S x,S y){
	if(x.a==y.a)return x.b<y.b;
	return x.a<y.a;
}
stack<int> st;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1,a;i<=n;i++){
		cin>>a;
		s[i]=s[i-1]^a;
		if(ma[(s[i]^m)]!=0){
			v.push_back({ma[(s[i]^m)]+1,i});
		}else if(s[i]==m){
			v.push_back({1,i});
		}
		ma[s[i]]=i;
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(st.empty())st.push(v[i].b);
		else{
			if(st.top()<v[i].a){
				st.push(v[i].b);
			}else{
				if(st.top()>v[i].b){
					st.pop();
					st.push(v[i].b);
				}
			}
		}
	}
	cout<<st.size();
	return 0;
}
/*
AK CSP-J
AK CSP-S
AK NOIP
AK 省选
AK NOI
AK IOI
*/