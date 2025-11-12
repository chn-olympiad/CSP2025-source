#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200100],s2[200100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i]; 
	}
	for(int i = 1;i <= q;i++){
		string t1,t2;
		int ans = 0;
		cin >> t1 >> t2;
		for(int j = 1;j <= n;j++){
			int t = t1.find(s1[j]);
//			int ts = t2.find(s2[j]);
			int len = s1[j].size();
			string tmp = t1;
			if(t == -1) continue;
			for(int k = t;k <= t + len - 1;k++){
				tmp[k] = s2[j][k - t];
			}
			cout << tmp << " " << t2 << "\n";
			if(tmp == t2) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
