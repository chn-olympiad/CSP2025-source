#include<bits/stdc++.h>
using namespace std;

string s1[200005],s2[200005];
string s;
bool pan(string q,string p){
	for(int i=0;i<q.size();i++){
		if(q[i]==p[0]){
			for(int j=0;j<p.size();j++) if(q[j+i]!=p[j]) return false;
		}
	}
	return true;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,cnt=0;
	cin >> n >> q;
	for(int i=1;i<=n;i++) scanf("%s %s",&s1[i],&s2[i]);
	cin >> s;
	for(int i=1;i<=n;i++) if(pan(s,s1[i]) || pan(s,s2[i])) cnt++;
	cout << cnt;
	return 0;
}
