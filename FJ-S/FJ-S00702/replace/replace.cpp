#include<bits/stdc++.h>
using namespace std;
string pat[200005][2];
int posb[200005][2];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out","w", stdout);
	ios::sync_with_stdio(0);
	int n,q;cin >> n >> q;
	for(int i=1;i<=n;i++)cin >> pat[i][0] >> pat[i][1]; 
	if(n>100){
		for(int x=1;x<=n;x++){
			for(int i=0;i<pat[x][0].size();i++){
				if(pat[x][0][i]=='b'){
					posb[x][0]=i;break;
				}
			}
			for(int i=0;i<pat[x][1].size();i++){
				if(pat[x][1][i]=='b'){
					posb[x][1]=i;break;
				}
			}
		}
	}
while(q--){
	string s,d;cin >> s >> d;
	if(s.size()!=d.size()){
		cout << "0\n";
		continue;
	}
	int ld=-1,rd,m=s.size(), ans=0;
	for(int i=0;i<m;i++){
		if(s[i]!=d[i]){
			rd=i;
			if(ld==-1)ld=i;
		}
	}if(n<=100){
		for(int i=0;i<=ld;i++){
			for(int j=1;j<=n;j++){
				int l=pat[j][0].size();
				if(i+l<=rd)continue;
				for(int k=0;k<l;k++){
					if(s[i+k]!=pat[j][0][k]||d[i+k]!=pat[j][1][k]){
						goto cont;
					}
				}ans+=1;
				cont:0;
			}
		}
	}else{
		int pb[2];
		for(int i=0;i<s.size();i++){
			if(s[i]=='b'){
				pb[0]=i;break;
			}
		}
		for(int i=0;i<d.size();i++){
			if(d[i]=='b'){
				pb[1]=i;break;
			}
		}for(int i=1;i<=n;i++){
			if(posb[i][0]-posb[i][1]==pb[0]-pb[1]&&pb[0]-posb[i][0]>=0&&pb[0]-posb[i][0]+pat[i][0].size()<=n){
				ans++;
			}
		}
	}cout << ans << "\n";
}
	return 0;
}
