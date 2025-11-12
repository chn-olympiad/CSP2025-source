#include<bits/stdc++.h>
using namespace std;

struct xieyin{
	string s1;
	string s2;
}ls[200010];
int n,q;
vector<int> aidx;

void sfind(string s,string t,int from = 0){
	if(s == t){
		aidx.push_back(from);
		return;
	}
	int l = s.size();
	if(from >= l)return;
	string tmp = s.substr(from,l-1);
	int pos = tmp.find(t);
	if(pos == -1)return;
	aidx.push_back(from + pos);
	sfind(s,t,from + pos + 1);
}

void Get(string s,string t){
	aidx.clear();
	sfind(s,t);
	if(aidx.empty())aidx.push_back(-1);
}

string Substr(string s,int l,int r){
	if(l > r)return "";
	string x = "";
	for(int i=l;i<=r;i++)
		x = x + s[i];
	return x;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>ls[i].s1>>ls[i].s2;
	for(int i=1;i<=q;i++){
		int cnt = 0;
		string Base;string Dream;
		cin>>Base>>Dream;
		for(int i=1;i<=n;i++){
			Get(Base,ls[i].s1);
			for(int ix:aidx){
				//cout<<ix<<" ";
				if(ix == -1)continue;
				string sPre = Substr(Base,0,ix-1);
				string sBak = Substr(Base,ix+(int)ls[i].s1.size(),Base.size()-1);
				string New = sPre + ls[i].s2 + sBak;
				//cout<<New<<endl;
				if(New == Dream)cnt++;
			}	
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 
