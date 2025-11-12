#include <bits/stdc++.h>
using namespace std;

int n,q;
string s[200005][4];
string ti,tj;

void bf(){
	string t; int ans=0;
	for(int i = 1; i<=n; i++){
		t=ti;
		for(int j = 0; j<t.size(); j++){
			t=ti;
			bool flag=true;
			for(int k = j; k<=j+s[i][1].size()-1; k++){
				if(t[k]^s[i][1][k-j]){
					flag=false; break;
				}
				if(tj[k]^s[i][2][k-j]){
					flag=false; break;
				}
			}
			if(flag){
				for(int k = j; k<=j+s[i][1].size()-1; k++) t[k]=s[i][2][k-j];
			//	cout<<t<<" "<<i<<'\n';
				if(t==tj) ans++;
			}
		}
	}
	cout<<ans<<'\n';
}

pair<int,int> df[200005][4],dti,dtj;

void B(){
	int cnt1=0;
	for(int j = 0; j<ti.size(); j++){
		if(ti[j]=='b') break;
		cnt1++;
	}
	dti=make_pair(cnt1,ti.size()-cnt1-1);
	cnt1=0;
	for(int j = 0; j<tj.size(); j++){
		if(tj[j]=='b') break;
		cnt1++;
	}
	dtj=make_pair(cnt1,tj.size()-cnt1-1);
	int ans=0;
	for(int i = 1; i<=n; i++){
		if(df[i][1].first>dti.first || df[i][1].second > dti.second) continue;
		if(df[i][2].first>dtj.first || df[i][2].second > dtj.second) continue;
		if(dtj.first-dti.first==df[i][2].first-df[i][1].first) ans++;
	}
	cout<<ans<<'\n';
}

/*
1 1
aaab abaa
aaaba abaaa
*/

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool b=true;
	for(int i = 1; i<=n; i++) cin>>s[i][1]>>s[i][2];
	for(int i = 1; i<=n; i++){
		int cnt=0; bool flag=true;
		for(auto t:s[i][1]){
			cnt+=(t=='b'); if(cnt>1) { flag=false; break; }
		}
		if(!flag) { b=false; break; }
	}
	for(int i = 1; i<=n; i++){
		int cnt1=0;
		for(int j = 0; j<s[i][1].size(); j++){
			if(s[i][1][j]=='b') break;
			cnt1++;
		}
		df[i][1]=make_pair(cnt1,s[i][1].size()-cnt1-1);
		cnt1=0;
		for(int j = 0; j<s[i][2].size(); j++){
			if(s[i][2][j]=='b') break;
			cnt1++;
		}
		df[i][2]=make_pair(cnt1,s[i][2].size()-cnt1-1);
	}
	for(int i = 1; i<=q; i++){
		cin>>ti>>tj;
		if(b) B();
		else if((n<=100&&q<=100) || q==1) bf();
	}
	return 0;
} 
//100+16+20+28=164
