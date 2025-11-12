#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200001][3];
string t1,t2,s1,s2;
long long ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i][1]>> s[i][2];
	}
	for(int T=1;T<=q;T++){
		ans=0;
		cin >> t1 >> t2;
		for(int i=1;i<=n;i++){
			s1=s[i][1];
			s2=s[i][2];
			for(int j=0;j+s[i][1].size()-1<t1.size();j++){
				string t3=t1;
				int flag=0;
				for(int k=0;k<s1.size();k++){
					if(t1[j+k]!=s1[k]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					for(int k=0;k<s2.size();k++){
						t3[j+k]=s2[k];
					}
				}
				if(t3==t2){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
