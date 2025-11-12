#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e3+5;
int n,m;
map <string,int> mp,mp1[N];
string a[N],b[N],s,t;
int calc(string s,string t){
	if(s.size()!=t.size())return 0;//没啥必要了
	int clen=s.size(),ans=0;
	s=" "+s,t=" "+t;
	int l = 0,r = clen+1;
	for(int i = 1;i <= clen;i++){
		if(s[i]==t[i]){
			l=i;
		}else break;
	}for(int i = clen;i >= 1;i--){
		if(s[i]==t[i]){
			r=i;
		}else break;
	}l++,r--;
	l=min(l,clen),r=max(r,1ll);
	for(int i = 1;i <= l;i++){
		string wyt,tlh;wyt.clear();tlh.clear();
		for(int j = i;j <= clen;j++){
			wyt.push_back(s[j]);
			tlh.push_back(t[j]);
			if(j>=r)ans+=mp1[mp[wyt]][tlh];
		}
	}return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		if(!mp[a[i]])mp[a[i]]=i;
		mp1[mp[a[i]]][b[i]]++;
	}
	for(int i = 1;i <= m;i++){
		cin >> s >> t;
		cout << calc(s,t) << "\n"; 
	}
	return 0;
}
//666神秘串串题
//屏幕前的朋友们觉得我hsh会被卡吗
//我只会O(nm)qmq
// 
