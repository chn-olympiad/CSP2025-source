#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int ans=0,f=1;
	while(c<48||c>57) (c==45?f=-1:1),c=getchar();
	while(c>=48&&c<=57) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}
#define pii pair<string,string>
#define pii1 pair<int,int>
map<pii,vector<pii1 > >mp;
/*
6 1
ab ba
aba aba
b b
ab ab
ba ba
aaaba aaaba 
aaba aaba
*/
main(){
//	system("fc replace4.ans replace.out");
//	freopen("replace4.in","r",stdin);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for (int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		while(l<s1.size()&&s1[l]==s2[l]) l++;
		while(r>=0&&s1[r]==s2[r]) r--;
		string s3="",s4="";
		for (int j=l;j<=r;j++) s3.push_back(s1[l]),s4.push_back(s2[l]);
		for (int i=0;i<s1.size();i++) if (s1[i]=='b'){
			mp[{s3,s4}].push_back({i+1,s1.size()-(i+1)+1});
			break;
		}
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if (s1.size()!=s2.size()){
			puts("0");
			continue;
		}
	//	cerr<<s1<<" "<<s2<<endl;
		int l=0,r=s1.size()-1;
		while(l<s1.size()&&s1[l]==s2[l]) l++;
		while(r>=0&&s1[r]==s2[r]) r--;
		string s3="",s4="";
		for (int j=l;j<=r;j++) s3.push_back(s1[l]),s4.push_back(s2[l]);
		int ans=0,x;
		for (int i=0;i<s1.size();i++) if (s1[i]=='b'){
			x=i+1;
			break;
		}
		for (auto i:mp[{s3,s4}]) ans+=(i.first<=x&&i.second<=s1.size()-x+1);
		printf("%lld\n",ans);
	}
	return 0;
}

