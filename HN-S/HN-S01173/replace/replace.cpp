#include<bits/stdc++.h>
#define int long long
using namespace std;

//const int maxn=;

int n,q;
map<string,string>f;

string sub(string s,int l,int r){
	string t;
	for (int i=l;i<=r;++i){
		t+=s[i];
	}
	return t;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace1.in","r",stdin);
	cin>>n>>q;
	for (int i=1;i<=n;++i){
		string a,b;
		cin>>a>>b;
		f[a]=b;
	}
	for (int i=1;i<=q;++i){
		string a,b;
		int ans=0;
		cin>>a>>b;
		for (int i=0;i<a.size();++i){
			for (auto t:f){
				string tf=t.first;
				string ftf=f[tf];
				int tfs=tf.size();
				string subal=sub(a,0,i-1);
				string subar=sub(a,i+tfs,a.size()-1);
				string suba=sub(a,i,i+tfs-1);
				string subb=sub(b,i,i+tfs-1);
//				printf("[debug]i=%d tfs-1=%d ans=%d | tf=%s ftf=%s suba=%s subb=%s | subal=%s subar=%s\n",i,tfs-1,ans,tf.c_str(),ftf.c_str(),suba.c_str(),subb.c_str(),subal.c_str(),subar.c_str());
				if (tf==suba&&ftf==subb&&subal+ftf+subar==b)++ans; 
//				printf("[debug]a=%s b=%s ans=%d t.first=%s f[t.first]=%s substr1=%s substr2=%s\n",a.c_str(),b.c_str(),ans,t.first.c_str(),f[t.first].c_str(),a.substr(i,i+t.first.size()).c_str(),b.substr(i,i+t.first.size())._str())
//				if (a.substr(i,i+t.first.size())==t.first&&b.substr(i,i+t.first.size())==f[t.first])++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

