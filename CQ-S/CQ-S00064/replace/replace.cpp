#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
int n,q;
const int maxn = 2e5 + 10,maxq = 2e5 + 10,p = 1e9 + 7,maxlen = 5e6 + 10;
string s[maxn][2];
ull haha[maxn][2];
ull Ts[maxlen];
ull h[maxlen][2];
int f[maxn][2],b[maxn][2];
//
bool isPF(){
	if(n > 1000 && q > 1000) return false;
	int len = 0;
	for(int i=1;i<=n;i++){
		len += s[i][0].length() + s[i][1].length();
	}
	return len < 2000;
}
bool isB(){
	if(n > 1000 && q > 1000) return false;
	for(int i=1;i<=n;i++){
		int A1 = 0,B1 = 0;
		for(char c:s[i][0]){
			if(c == 'a') A1++;
			if(c == 'b') B1++;
		}
		if(!(A1 == s[i][0].size() - 1 && B1 == 1)) return false;
		A1 = 0,B1 = 0;
		for(char c:s[i][1]){
			if(c == 'a') A1++;
			if(c == 'b') B1++;
		}
		if(!(A1 == s[i][1].size() - 1 && B1 == 1)) return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	if(isPF() && 0){
		Ts[0] = 1;
		for(int i=1;i<=5000000;i++) Ts[i] = Ts[i-1] * p;
		for(int i=1;i<=n;i++){
			for(char c:s[i][0]){
				haha[i][0] = haha[i][0] * p + c;
			}
			for(char c:s[i][1]){
				haha[i][1] = haha[i][1] * p + c;
			}
		}
		int len = 0;
		while(q--){
			for(int i=0;i<=len;i++) h[i][0] = h[i][1] = 0;
			string x,y;
			cin>>x>>y;
			len = x.length();
			x = '$' + x,y = '$' + y;
			for(int i=1;i<=len;i++){
				h[i][0] = h[i-1][0] * p + x[i];
				h[i][1] = h[i-1][1] * p + y[i];
			}
			int L = 1,R = len;
			while(L <= len && x[L] == y[L]) L++;
			while(R >= 1 && x[R] == y[R]) R--;
			ll ans = 0;
			for(int i=1;i<=n;i++){
				for(int l=max(1,(int)(R-s[i][0].length()+1));l<=min(n,(int)(L+s[i][0].length()-1));l++){
					int r = l + s[i][0].length() - 1;
					if(h[r][0] - h[l-1][0] * Ts[s[i][0].length()] == haha[i][0]
					&& h[r][1] - h[l-1][1] * Ts[s[i][0].length()] == haha[i][1]){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(isB()){
		for(int i=1;i<=n;i++){
			int pos = 0;
			while(pos < s[i][0].length() && s[i][0][pos] != 'b') pos++;
			f[i][0] = pos,b[i][0] = s[i][0].length()-pos-1;
//			cout<<pos<<'\n';
			pos = 0;
			while(pos < s[i][0].length() && s[i][1][pos] != 'b') pos++;
			f[i][1] = pos,b[i][1] = s[i][1].length()-pos-1;
//			cout<<f[i][0]<<' '<<b[i][0]<<' '<<f[i][1]<<' '<<b[i][1]<<'\n';
		}
		int len = 0;
		while(q--){
			string x,y;
			cin>>x>>y;
			len = x.length();
			x = '$' + x,y = '$' + y;
			int posx = 1,posy = 1;
			while(posx <= len && x[posx] != 'b') posx++;
			while(posy <= len && y[posy] != 'b') posy++;
			int ans = 0;
//			cout<<posx<<' '<<posy<<'\n';
			for(int i=1;i<=n;i++){
				if(f[i][0] <= posx-1 && b[i][0] <= len-posx && f[i][1] <= posy-1 && b[i][1] <= len-posy){
					ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	return 0;
}
