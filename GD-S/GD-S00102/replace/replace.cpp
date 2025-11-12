#include<bits/stdc++.h>
using namespace std;
int n, q, a[200005][3];
string s[200005][3],ta,tb;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>s[i][1]>>s[i][2];
		for(int j=0; j<s[i][1].size(); j++){
			if(s[i][1][j]=='b'){
				a[i][1]=j;
				break;
			}
		}
		for(int j=0; j<s[i][2].size(); j++){
			if(s[i][2][j]=='b'){
				a[i][2]=j;
				break;
			}
		}
	}
	while(q--){
		cin>>ta>>tb;
		int ans=0, d, f;
		for(int j=0; j<ta.size(); j++){
			if(ta[j]=='b'){
				d=j;
				break;
			}
		}
		for(int j=0; j<tb.size(); j++){
			if(tb[j]=='b'){
				f=j;
				break;
			}
		}
		for(int i=1; i<=n; i++){
			if(a[i][2]-a[i][1]==f-d) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

