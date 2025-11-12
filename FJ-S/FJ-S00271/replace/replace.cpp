#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
	}
	while(q--){
		int ans=0;
		cin >> t1 >> t2;
		int len=t1.size();
		if(len!=t2.size()){cout << "0\n";continue;}
		t1=" "+t1;
		t2=" "+t2;
		for(int i=1;i<=n;i++){
			int p=0;
			string s=t1;
			while(1){
				int pos=s.find(s1[i],p);
				for(int j=p;j<pos;j++) s[j]=0;
				p=pos+1;
				if(pos==-1) break;
				bool flag=0;
				int j;
				for(j=1;j<pos;j++){
					if(t1[j]!=t2[j]){
						flag=1;
						break;
					}
				}
				if(flag) break;
				for(j=0;j<s2[i].size();j++){
					if(s2[i][j]!=t2[j+pos]){
						flag=1;
						break;
					}
				}
				if(flag) continue;
				for(j=pos+s2[i].size();j<=len;j++){
					if(t1[j]!=t2[j]){
						flag=1;
						break;
					}
				}
				if(flag) continue;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
