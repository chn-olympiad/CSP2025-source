#include<bits/stdc++.h>
#define endl '\n'
#define debug(x) cerr<<#x<<':'<<x<<endl
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n,q;
map<pair<vector<string>,vector<string> >,int> cnt;
pair<vector<string>,vector<string> > solve(string s,string t){
	int x=s.size();
	int l=0,r=x-1;
	for(int i=0;i<x;i++){
		if(s[i]==t[i]) l++;
		else break;
	}
	for(int i=x-1;i>=l;i--){
		if(s[i]==t[i]) r--;
		else break;
	}
	string sx,sy,sz,tx,ty,tz;
	for(int i=0;i<l;i++) sx+=s[i],tx+=t[i];
	for(int i=l;i<=r;i++) sy+=s[i],ty+=t[i];
	for(int i=r+1;i<x;i++) sz+=s[i],tz+=t[i];
	vector<string> S,T;
	S.push_back(sx),S.push_back(sy),S.push_back(sz);
	T.push_back(tx),T.push_back(ty),T.push_back(tz);
	return {S,T};
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	IOS;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		cnt[solve(a,b)]++;
	}
	while(q--){
		debug(q);
		string a,b;
		cin>>a>>b;
		auto x=solve(a,b);
		string s1,t1;
		int ans=0;
		vector<string> A,B;
		for(int i=x.first[0].size();i>=0;i--){
			if(i<x.first[0].size()){
				s1=x.first[0][i]+s1;
				t1=x.second[0][i]+t1;
			}
			string s3,t3;
			
			for(int j=-1;j<(int)x.first[2].size();j++){
				if(j>=0){
					s3=s3+x.first[2][j];
					t3=t3+x.second[2][j];
				}
				A.clear(),B.clear();
				A.push_back(s1),A.push_back(x.first[1]),A.push_back(s3);
				B.push_back(t1),B.push_back(x.second[1]),B.push_back(t3);
				ans+=cnt[{A,B}];
				/*
				cout<<A[0]<<' '<<A[1]<<' '<<A[2]<<endl;
				cout<<B[0]<<' '<<B[1]<<' '<<B[2]<<endl;
				*/
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

