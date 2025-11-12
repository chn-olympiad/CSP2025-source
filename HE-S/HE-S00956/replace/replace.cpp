#include<bits/stdc++.h>
using namespace std;
pair<string,string> s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i].first >> s[i].second;
	}
	while(q--){
		long long ans=0;
		string t01,t02,a,b;
		cin >> t01 >> t02;a=b=t01;
		for(int i=1;i<=n;i++){
			a=b=t01;
			while(b.find(s[i].first) >= 0 && b.find(s[i].first)<=b.length()-s[i].first.length()){
				a = t01;
				a.replace(b.find(s[i].first),s[i].first.length(),s[i].second);
				b[b.find(s[i].first)]='^';
				if(a==t02) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
