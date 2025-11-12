#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef pair<string,string> PSS;
int n,q;
PSS s[N];
string t1,t2;
int nxt[N];
void getnxt(const string& s){
	for (int i=0;i<(int)s.size();i++)
		nxt[i]=0;
	for (int i=1;i<(int)(int)s.size();i++){
		int j=nxt[i-1];
		while (j&&s[j]!=s[i]) j=nxt[j];
		nxt[i]=(s[i]==s[j] ? j+1:j);
	}
}
bool cmp(PSS a,PSS b){ return a.first.size()>b.first.size();}
bool kmp(const string& s,const string& t,int l,int r){
	getnxt(t);
	int j=0;
	for (int i=0;i<(int)s.size();i++){
		if (t[j]!=s[i]) j=nxt[j];
		else{
			j++;
			if (j==(int)t.size())
				if (i>=r&&i-(int)t.size()+1<=l)
					return 1;
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>s[i].first>>s[i].second;
	sort(s+1,s+n+1,cmp);
	for (int i=1;i<=q;i++){
		cin>>t1>>t2;
		getnxt(t1);
		if (t1.size()!=t2.size()) {cout<<"0\n";continue;}
		int l=-1,r=0;
		for (int j=0;j<(int)t1.size();j++){
			if ((l<0)&&t1[j]!=t2[j]) r=l=j;
			else if (t1[j]!=t2[j]) r=j;
		}
		int ans=0;
		for (int j=1;j<=n&&(int)s[j].first.size()>=r-l+1;j++){
			cout<<j<<endl;
			if (kmp(t1,s[j].first,l,r)&&kmp(t2,s[j].second,l,r))
				ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
