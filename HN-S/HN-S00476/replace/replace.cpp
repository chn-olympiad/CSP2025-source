#include<bits/stdc++.h>
using namespace std;
struct replaced{
	string a;
	string b;
};
struct replaced a[200010];
inline int finds(string s,string a){
	for(int i=0;i<s.length();i++){
		bool k=1;
		for(int j=i;j<a.length();j++){
			if(s[j] != a[j-i]){
				k = 0;
				break;
			}
		}
		if(k) return i;
	}
	return -1;
}
inline string replaces(string s,string a,int k){
	for(int i=0;i<a.length();i++){
		s[k+i] = char(a[i]);
	}
	return s;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>a[i].a>>a[i].b;
	for(int i=0;i<q;i++){
		string s;
		string p;
		cin>>s>>p;
		int ans=0;
		for(int i=0;i<n;i++){
			int k = finds(s,a[i].a);
			if(k != -1){
				string s1 = replaces(s,a[i].b,k);
				if(s1 == p) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
