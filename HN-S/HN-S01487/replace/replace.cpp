#include<bits/stdc++.h>
using namespace std;
const int N=1010;
vector<int>p[N][3];
string s[N][3];
int vis[N],siz[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s[i][1]+='a';
		for(int j=0;j<s1.size();j++){
			s[i][1]+=s1[j];
		}
		s[i][2]+='a';
		for(int j=0;j<s2.size();j++){
			s[i][2]+=s2[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int d=1;d<=2;d++){
			int k=0;
			p[i][d].push_back(0);
			p[i][d].push_back(0); 
			for(int j=1;j<s[i][d].size()-1;j++){
				while(k>0&&s[i][d][k+1]!=s[i][d][j+1]){
					k=p[i][d][k];
				}
				if(s[i][d][k+1]==s[i][d][j+1]){
					k++;
				}
				p[i][d].push_back(k);
			}
		}
		int l=0,r=0;
		for(int j=1;j<s[i][1].size();j++){
			if(s[i][1][j]!=s[i][2][j]){
				l=j;
				break;
			}
		}
		for(int j=s[i][1].size()-1;j>=1;j--){
			if(s[i][1][j]!=s[i][2][j]){
				r=j;
				break;
			}
		}
		siz[i]=r-l+1;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int l=0,r=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
		}
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		int len=r-l+1;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i][1].size()-1>s1.size()||siz[i]!=len){
				continue;
			}
			int k=0;
			for(int j=0;j<s1.size();j++){
				while(k>0&&s[i][1][k+1]!=s1[j]){
					k=p[i][1][k];
				}
				if(s[i][1][k+1]==s1[j]){
					k++;
				}
				if(k==s[i][1].size()-1){
					vis[j]=i;
					k=p[i][1][k];
				}
			}
			k=0;
			for(int j=0;j<s2.size();j++){
				while(k>0&&s[i][2][k+1]!=s2[j]){
					k=p[i][2][k];
				}
				if(s[i][2][k+1]==s2[j]){
					k++;
				}
				if(k==s[i][1].size()-1){
					if(vis[j]==i){
						ans++;
					}
					k=p[i][2][k];
				}
			}
		}
		cout<<ans<<endl;
		for(int j=0;j<s1.size();j++){
			vis[j]=0;
		}
	}
	return 0;
}
