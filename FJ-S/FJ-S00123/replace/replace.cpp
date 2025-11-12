#include <bits/stdc++.h>
#include <set>
using namespace std;
string s1[200010],s2[200010];
multiset<pair<int,pair<int,int>>> s;
int cnt;
void solve1(string t1,string t2){
	int sz=t1.size(),p1=t1.find('b'),p2=t2.find('b');
	for (auto i:s){
		if (p1-p2==i.second.first-i.second.second
			&&sz-p1-1>=i.first-i.second.first-1
			&&p1>=i.second.first){
			cnt++;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,Q;
	scanf("%d%d",&n,&Q);
	int flg=1;
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		if (flg){
			for (int j=0;j<s1[i].size();j++){
				if ((s1[i][j]!='a'&&s1[i][j]!='b')||(s2[i][j]!='a'&&s2[i][j]!='b')){
					flg=0;
					break;
				}
			}
			s.insert({s1[i].size(),{s1[i].find('b'),s2[i].find('b')}});
		}
	}
	string t1,t2;
	while (Q--){
		cnt=0;
		cin>>t1>>t2;
		if (flg){
			solve1(t1,t2);
		}
		else{
			for (int i=1;i<=n;i++){
				if (s1[i]==s2[i]&&t1[i]==t2[i]){
					for (int j=0;j<n-s1[i].size()+1;j++){
						if (t1.substr(j,s1[i].size())==s1[i]){
							cnt++;
						}
					}
					break;
				}
				int p=t1.find(s1[i]);
				if (p!=t1.npos){
					string t=t1;
					t.replace(p,s1[i].size(),s2[i]);
					if (t==t2){
						cnt++;
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
