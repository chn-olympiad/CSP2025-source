#include<bits/stdc++.h>
using namespace std;
char c[5000005],c1[5000005],ch[500005];
string s[200005],s1[200005];
long long n,q,i,l,r,ans,df,j,ldf;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(i=1;i<=n;i++)cin >> s[i] >> s1[i];
	while(q--){
		ans = 0;
		cin >> c >> c1;
		df = 0;
		memset(ch,' ',sizeof(ch));
		int w = strlen(c);
		for(i=0;i<w;i++){
			ch[i] = c1[i];
			if(c[i] != c1[i])df++;
		}
		for(i=1;i<=n;i++){
			int v = s[i].size();
			if(v < df)continue;
			l = 0;
			r = s[i].size()-1;
			int g = strlen(c);
			while(r <= g){
				if(c[l]!=s[i][0]||c[r]!=s[i][s[i].size()-1]){
					l++;
					r++;
					continue;
				}
				ldf = df;
				for(j=l;j<=r;j++){
					if(c[j] == s[i][j-l]){
						if(c[j] != c1[j] && ch[j] == s1[i][j-l])ldf--;
					}
				}
				if(ldf == 0)ans++;
				l++;
				r++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
