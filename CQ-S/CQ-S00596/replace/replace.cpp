#include <bits/stdc++.h>
using namespace std;
//ÆÚÍû 10
string a[1100000];
string a2[1100000];
map<string,int> mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	freopen("replace.in","r",stdin);	
	freopen("replace.out","w",stdout);	
	int n,q;
	cin >> n >> q;
		bool fa=1;
		for(int i=1;i<=n;i++){
			cin >> a[i] >> a2[i];
			mp[a[i]]=i;
		}
		while(q--){//q 
			string s,s2;
			int cnt=0;
			cin >> s >> s2;
			string qian="";
			for(int i=0;i<=s.size()-1;i++){//L
				string k="";
				for(int j=i;j<=s.size()-1;j++){//L
					k+=s[j];
					if(mp[k]!=0){//logn
						int p=mp[k];
						string lk=qian+a2[p];
						for(int pp=j+1;pp<=s.size()-1;pp++) lk+=s[pp];
						if(lk==s2)cnt++;
					}
				}
				qian+=s[i];
			}
			cout << cnt << "\n";
		}
//	}
	
	return 0;
}


