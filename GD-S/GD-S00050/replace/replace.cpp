#include<bits/stdc++.h>
using namespace std;
int n, q, ans;
string s[200010][3], s1, s2;
bool check(int f, int t){
	string ss="", ss2="";
	for(int i=f; i<=t; i++){
		ss=ss+s1[i];
		ss2=ss2+s2[i];
	}
	for(int i=1; i<=n; i++){
		if(ss==s[i][1] && s[i][2]==ss2){
			return true;
		}
	}
	return false;
} 
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>s1>>s2;
		ans=0;
		if(check(0, (int)(s1.size()-1))){
			ans++;
		}
		for(int i=0; i<(int)(s1.size()); i++){
			if(s1[i]!=s2[i]){
				break;
			}
			for(int j=(int)(s2.size()-1); j>=0; j--){
				if(s1[j]!=s2[j]){
					break;
				}
				if(check(i, j)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

