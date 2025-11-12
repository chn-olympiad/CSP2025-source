#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#define N 200005
using namespace std;
int n,Q;
string s[N][2];
string p,q;
bool check(string x,string y){
	return x==y;
}
int rp(int i){
	int res=0;
	for(int j=0;j+s[i][0].size()-1<p.size();j++){
		if(check(p.substr(j,s[i][0].size()),s[i][0]))
			if((p.substr(0,j)==q.substr(0,j)||j==0)&&(p.substr(j+s[i][0].size())==q.substr(j+s[i][0].size())||j+s[i][0].size()>=q.size())&&s[i][1]==q.substr(j,s[i][0].size()))
				res++;
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(Q--){
		cin>>p>>q;
		if(p.size()!=q.size()){
			cout<<0<<'\n'; 
			continue;
		}
		int res=0;
		for(int i=1;i<=n;i++)
			res+=rp(i);
		cout<<res<<'\n';
	}
	return 0;
}
