#include <bits/stdc++.h>
using namespace std;
int n,q;
string s,s1,s2,s3,s4,s5,s6;
map<string,string> mp;
map<int,string> mp2;
bool cmp(string a,string b){
	int hh=a.size();
	for(int i=0;i<hh;i++)
		if(a[i]!=b[i]) return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin >> n >>q;
	for(int i=1;i<=n;i++)
		cin >> s >> s1,mp[s]=s1,mp2[i]=s;
	while(q--){
		cin >> s >> s1;
		int h=s.size(),h1=s1.size(),cnt=0;
		if(h!=h1){cout << 0 << "\n";continue;}
		for(int i=1;i<=n;i++){
			int k=mp2[i].size();
			for(int j=0;j<=h-k;j++){
				s2=s3;s4=s3;s5=s3,s6=s3;
				for(int l=0;l<h;l++)
					if(j<=l && l<j+k)s2+=s[l],s4+=s1[l];
					else s5+=s[l],s6+=s1[l];
				if(cmp(s2,mp2[i])==1 && cmp(s4,mp[mp2[i]])==1 && cmp(s5,s6)==1)cnt++;
			}
		} 
		cout << cnt << "\n";
	}
	return 0; 
} 
