#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,q;
pair<string,string>s[N],t;
const int L=5e6+3;
int nxt[L]={-1};
void getnxt(string s2){
	int t1=0,t2=-1;
	while(t1<s2.size()){
		if(t2==-1||s2[t1]==s2[t2])	nxt[++t1]=t2;
		else	t2=nxt[t2];
	}
	return ;
}
bool ans[2][L];
void kmp(string s1,string s2,int op){
	for(int i=0;i<=s1.size();i++)	ans[op][i]=0;
	int t1=0,t2=0;
	while(t1<s1.size()){
		if(t2==-1||s1[t1]==s2[t2])	t1++,t2++;
		else	t2=nxt[t2];
		if(t2==s2.size()){
			ans[op][t1-t2+1]=1;
			t2=nxt[t2];
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)	cin>>s[i].first>>s[i].second;
	while(q--){
		int anss=0;
		cin>>t.first>>t.second;
		if(t.first.size()!=t.second.size()){
			cout<<0<<'\n';
			continue;
		}
		for(int j=1;j<=n;j++){
			if(s[j].first.size()!=s[j].second.size())	continue;
			getnxt(s[j].first);
			kmp(t.first,s[j].first,0);
			getnxt(s[j].second);
			kmp(t.second,s[j].second,1);
			for(int k=0;k<=min(t.first.size(),t.second.size());k++){
				if(t.first.substr(0,k-1)!=t.second.substr(0,k-1))	continue;
				if(k+s[j].first.size()-1>t.first.size())	continue;
				if(t.first.substr(k+s[j].first.size()-1)!=t.second.substr(k+s[j].first.size()-1))	continue;
				if(ans[0][k]&&ans[1][k])	anss++;
			}
		}
		cout<<anss<<'\n';
	}
	return 0;
}