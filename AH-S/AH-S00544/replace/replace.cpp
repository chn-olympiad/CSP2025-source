#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
struct Node {
	string s1;
	string s2;
	int w1,w2;
}p[100005];
string from;
string to;
int ans=0;
bool check(int now,int bg) {
	string sa=from;
	for(int i=bg;i<bg+(int)p[now].s1.size();i++) {
		if(sa[i]!=p[now].s1[i-bg]) return false;
		sa[i]=p[now].s2[i-bg];
	}
	if(sa==to) return true;
	return false;
}
bool check2(string s) {
	for(int i=0;i<(int)s.size();i++) 
		if(s[i]!='a'||s[i]!='b') 
			return false;
	return true;
}
int find(string s) {
	for(int i=0;i<(int)s.size();i++) 
		if(s[i]=='b') 
			return i;
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>p[i].s1>>p[i].s2;
	if(check2(p[1].s1)&&check2(p[n].s1)&&check2(p[n/2].s1)) {
		for(int i=1;i<=n;i++) {
			p[i].w1=find(p[i].s1);
			p[i].w2=find(p[i].s2);
		}
		for(int i=1;i<=m;i++) {
			ans=0;
			int wf,wt;
			cin>>from;
			cin>>to;
			wf=find(from);
			wt=find(to);
			for(int i=1;i<=n;i++) 
				if(wf>p[i].w1&&wt<(int)p[i].s1.size()-p[i].w1&&wf-p[i].w1+p[i].w2==wt)
					ans++;
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=m;i++) {
		ans=0;
		cin>>from;
		cin>>to;
		for(int k=1;k<=n;k++)
			for(int j=0;j<=(int)from.size()-(int)p[k].s1.size();j++) 
				if(check(k,j)) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
