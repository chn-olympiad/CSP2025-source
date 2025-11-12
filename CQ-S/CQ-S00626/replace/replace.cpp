#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
int n,q,ne[N*50];
vector<int> KMP(string s,string t){
	vector<int> ans;
	int n=s.size(),m=t.size();
	s=" "+s;t=" "+t;
	for(int i=2,j=0;i<=m;i++){
		while(j&&t[j+1]!=t[i])j=ne[j];
		if(t[j+1]==t[i])j++;
		ne[i]=j;
	}
	for(int i=1,j=0;i<=n;i++){
		while(j&&t[j+1]!=s[i])j=ne[j];
		if(t[j+1]==s[i])j++;
		if(j==m)ans.push_back(i-m+1);
	}
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			puts("0");
			continue;
		}
		int l=t1.size(),r=0,ans=0;
		for(int i=0;i<t1.size();i++)
			if(t1[i]!=t2[i]){
				l=min(l,i+1);r=max(r,i+1);
			}
		for(int i=1;i<=n;i++){
			vector<int> v1=KMP(t1,s1[i]);
			vector<int> v2=KMP(t2,s2[i]);
			if(v1.size()&&v2.size()){
				for(auto p:v1){
					if(p<=l&&p+s1[i].size()-1>=r){
						string a="";
						for(int j=1;j<p;j++)a+=t1[j-1];
						for(int j=p;j<=p+s1[i].size()-1;j++)a+=s2[i][j-p];
						for(int j=p+s1[i].size()-1;j<t1.size();j++)a+=t1[j];
						bool flag=1;
						for(int j=0;j<t1.size();j++)
							if(a[j]!=t2[j]){
								flag=0;break;
							}
						if(flag){
							ans++;break;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

