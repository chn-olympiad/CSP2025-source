#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n, q;
string s1[N], s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
		string a, b;
		int len=s1[i].size();
		for(int j=0;j<len;j++){
			if(s1[i][j]==s2[i][j]){
				a+=" ",b+=" ";
			}else{
				a+=s1[i][j],b+=s2[i][j];
			}
		}
		string aa, bb;
		int ss, tt;
		for(int j=0;j<len;j++){
			if(a[j]!=' '){
				ss=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--){
			if(a[j]!=' '){
				tt=j;
				break;
			}
		}
		for(int j=ss;j<=tt;j++){
			aa+=a[j],bb+=b[j];
		}
		s1[i]=aa,s2[i]=bb;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string a, b, x, y;
		cin >> x >> y;
		int len=x.size();
		for(int j=0;j<len;j++){
			if(x[j]==y[j]){
				a+=" ",b+=" ";
			}else{
				a+=x[j],b+=y[j];
			}
		}
		string aa, bb;
		int ss, tt;
		for(int j=0;j<len;j++){
			if(a[j]!=' '){
				ss=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--){
			if(a[j]!=' '){
				tt=j;
				break;
			}
		}
		for(int j=ss;j<=tt;j++){
			aa+=a[j],bb+=b[j];
		}
		for(int j=1;j<=n;j++){
			if(aa==s1[j] && bb==s2[j]){
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

