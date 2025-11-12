#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
map<string,vector<pair<ull,ull> > > ans;
void input(string s1,string s2){
	string s1to="",s2to="",s3 = "";
	int pos1 = 0,pos2 = 0;
	int l = s1.length();
	for(int j = 0;j<l;j++)
		if(s1[j]!=s2[j]){
			pos1 = j;
			break;
		}
	for(int j = l-1;j>=0;j--)
		if(s1[j]!=s2[j]){
			pos2 = j;
			break;
		}
	for(int j = pos1;j<=pos2;j++){
		s1to+=s1[j],s2to+=s2[j];
	}
	ull has1=0,has2=0;
	for(int j = pos1-1;j > 0;j--){
		has1 = has1*31 + (s1[j] - 'a' + 1);
	}
	for(int j = pos2 + 1;j<l;j++){
		has2 = has2*31 + (s1[j] - 'a' + 1);
	}
	ans[s1to + " to " + s2to].push_back(make_pair(has1,has2));
}
set<ull> hashleft,hashright;
void solve(string s1,string s2){
	hashleft.clear();
	hashright.clear();
	
	string s1to="",s2to="",s3 = "";
	int pos1 = 0,pos2 = 0;
	int l = s1.length();
	for(int j = 0;j<l;j++)
		if(s1[j]!=s2[j]){
			pos1 = j;
			break;
		}
	for(int j = l-1;j>=0;j--)
		if(s1[j]!=s2[j]){
			pos2 = j;
			break;
		}
	for(int j = pos1;j<=pos2;j++){
		s1to+=s1[j],s2to+=s2[j];
	}
	ull has1=0,has2=0;
	hashleft.insert(has1);
	hashright.insert(has2);
	for(int j = pos1-1;j > 0;j--){
		has1 = has1 * 31 + (s1[j] - 'a' + 1);
		hashleft.insert(has1);
	}
	for(int j = pos2 + 1;j<l;j++){
		has2 = has2 * 31 + (s1[j] - 'a' + 1);
		hashright.insert(has2);
	}
	int ans1 = 0;
	for(vector<pair<ull,ull> >::iterator it = ans[s1to+" to "+s2to].begin();it!=ans[s1to+" to "+s2to].end();it++){
		pair<ull,ull> xx = *it;
		if(hashleft.count(xx.first) && hashright.count(xx.second)){
			ans1++;
		}
	}
	cout<<ans1<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//freopen
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1==s2)continue;
		input(s1,s2);
	}
	for(int i = 1;i <= q;i++){
		string s1,s2;
		cin>>s1>>s2;
		solve(s1,s2);
	}
	return 0;
}//there is hope as long as i live
