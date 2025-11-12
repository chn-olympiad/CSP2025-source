#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string str1,str2,p;
unordered_map<string,int> mp;
int n,q;
int l,r,ans;
struct ms {
	string s1,s2;
	int lng;
} a[N];
string subs(string s,int l,int r) {
	p="";
	l--,r--;
	for(int i=l;i<=r;i++) p=p+s[i];
	return p;
}
string qrr(string s,int l,int pos) {
	l--;
	for(int i=l;i<l+a[pos].lng;i++) s[i]=a[pos].s2[i-l];
	return s;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>str1>>str2;
		a[i].s1=str1,a[i].s2=str2,a[i].lng=str1.size();
		mp[str1]++;
	}
	for(int i=1;i<=q;i++) {
		cin>>str1>>str2;
		ans=0;
		int ln=str1.size();
		if(ln!=str2.size()) {
			cout<<0<<endl;
			continue;
		}
		for(int ll=1;ll<=n;ll++) {
			for(int rr=1;rr<=ln-a[ll].lng+1;rr++) {
				if(subs(str1,rr,rr+a[ll].lng-1)==a[ll].s1&&qrr(str1,rr,ll)==str2) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
//像是匹配模式串板子
//可是我完全忘了
//爆炸了，打个暴力走人了 
