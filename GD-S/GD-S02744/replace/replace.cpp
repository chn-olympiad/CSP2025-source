#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e5+10;
int n,m,q,a[N];
int f[N];
string s1[N],s2[N];
string t1,t2;
int tr[N],len[N];
char tmp[5000005];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len[i] = s1[i].length();
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int slen = t1.length();
		int st = 0,en = 0;
		for(int i=0;i<slen;i++){
			if(t1[i]!=t2[i]){
				st = i;
				break;
			}
		}
		for(int i=slen-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				en = i;
				break; 
			}
		}
		int ans = 0;
		for(int j=1;j<=n;j++){
			if(len[j]<en-st+1) continue;
			int lim = min(slen-len[j]+1,st+1);
			int stt = en-len[j]+1;
			if(stt<0) stt = 0;
			for(int l=stt;l<lim;l++){
				bool flag = 1;
				for(int k=0;k<len[j];k++){
					if(s1[j][k]!=t1[l+k]){
						flag = 0;
						break;
					}
				}
				if(!flag) continue;
				for(int k=0;k<len[j];k++){
					if(s2[j][k]!=t2[l+k]){
						flag = 0;
						break;
					}
				}
				if(!flag) continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
