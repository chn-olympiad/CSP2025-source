#include <bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,a[N],v[N],ans;
string s;
map<string,int> st;
void dfs(int cnt,string s1){
	if(cnt==n){
//		sort(v+1,v+1+n);
//		cout<<s1<<" "<<st[s1]<<"\n";
		if(!st[s1]){
			st[s1]++;
			int cntt=0,tnc=0;
			for(int i=0;i<n;i++){
				if(s[i]=='1'&&a[s1[i]-'0']-tnc>0){
					cntt++;
				}else{
					tnc++;
				}
			}
//			cout<<cntt<<"  a"<<tnc<<"\n";
			if(cntt>=m){
				ans++;
//				cout<<s1<<"\n";
			}
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=cnt+1;
		string ss=s1;
		ss+=('0'+i);
		dfs(cnt+1,ss);
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		for(int i=0;i<n;i++){
			if(s[i]!='1'){
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
		}
//		cout<"a";
		cout<<ans;
	}else{
		int anss=0;
		for(int i=0;i<n;i++){
			if(s[i]!='0'){
				anss++;
			}
		}
		if(anss<m){
			cout<<0;
			return 0;
		}
		dfs(0,"");
		cout<<ans;
	}
	return 0;
}
