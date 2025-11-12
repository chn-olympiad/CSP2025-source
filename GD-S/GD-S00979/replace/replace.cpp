#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,q;string s[N][10],t1,t2;
void solve1(){
	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s[i][1] >> s[i][2];
	}
	while(q--){
		cin >> t1 >> t2;
		int ans=0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < t1.size(); j++){
				int f=1;
				for(int k = 0; k < s[i][1].size();k++){
					if(j+k>=t1.size()){f=0;break;}
					if(t1[j+k]!=s[i][1][k])f=0;
				}
				if(f){
					string t3=t1;
					for(int k = 0; k < s[i][1].size(); k++){
						t3[j+k]=s[i][2][k];
					}
					if(t2==t3)ans++;
				}
			}
		}
		cout << ans << endl;
	}
	

	return 0;
}

