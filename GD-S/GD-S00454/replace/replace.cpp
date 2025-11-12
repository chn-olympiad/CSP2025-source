#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		mp[s1] = s2;
		mp[s2] = s1;
	}
	while(m--){
		string q1,q2;
		cin >> q1 >> q2;
		int cnt = 0,len = q1.size();
		if(mp[q1] == q2)cnt++;
		for(int i = 0;i < len;i++){
			if(q1[i] == q2[i]){
				string t1,t2,l1,l2;
				for(int j = i + 1,k = len - 1;j < len;j++,k--){
					t1 += q1[j],t2 += q2[j],l1 += q1[k],l2 += q2[k];
					if(l1 == l2)if(mp[t1] == t2)cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	
	return 0;
} 
