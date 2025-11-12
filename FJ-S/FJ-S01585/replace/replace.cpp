#include<bits/stdc++.h>
using namespace std;
struct xybh{
	long long bwz,len,bh;
}s[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin >> n >> q;
	for(long long i=0;i<n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		s[i].bwz = s1.find("b");
		s[i].len = s1.length();
		s[i].bh = s2.find("b")-s1.find("b");
	}
	for(long long i=0;i<q;i++){
		string s1,s2;
		cin >> s1 >> s2;
		if(s1.length()!=s2.length()){
			cout << "0\n";
			continue;
		}
		long long ans=0,bwz=s1.find("b"),len=s1.length(),bh=s2.find("b")-s1.find("b");
		for(long long j=0;j<n;j++){
			if(bh==s[j].bh){
				if(bwz>=s[j].bwz&&len-bwz>=s[j].len-s[j].bwz){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
