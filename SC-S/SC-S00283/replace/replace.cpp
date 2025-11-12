#include<bits/stdc++.h>
using namespace std;
#define int long long
map<string,string> mp;
string s1[200010],s2[200010]; 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		mp[s1[i]]=s2[i];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int lena=a.length(),lenb=b.length();
		if(lena!=lenb){
			cout<<"0\n";
			continue;
		}
		if(lena>1000){
			int idx1=0,idx2=0;
			for(int i=0;i<lena;i++){
				if(a[i]=='b'){
					idx1=i;
					break;
				}
			}
			for(int i=0;i<lenb;i++){
				if(b[i]=='b'){
					idx2=i;
					break;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(s1[i].find('b')-s2[i].find('b')==idx1-idx2) ans++;
			}
			cout<<ans<<'\n';
			continue;
		}
		string x="";
		int cnt=0;
		for(int i=0;i<lena;i++){//枚举x的初始位置 
			for(int j=1;j<=lena-i;j++){
				string y="",z="";
				for(int k=i;k<i+j;k++) y+=a[k];
				if(mp.find(y)==mp.end()) continue;
				for(int k=i+j;k<lena;k++) z+=a[k];
//				cout<<x<<' '<<y<<' '<<z<<'\n';
				if(x+mp[y]+z==b) cnt++;
			}
			x+=a[i];
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
