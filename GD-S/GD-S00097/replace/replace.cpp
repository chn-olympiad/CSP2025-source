#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,qq;
string s[N][2],s1,s2;
int p[N],f[N],q[N],b[N];
void ps(string s,string s1){
	s=s+'#'+s1;
	for(int i=1;i<s.size();i++){
		int j=p[i-1];
		while(j&&s[j]!=s[i]){
			j=p[j-1];
		}if(s[i]==s[j]){
			j++;
		}p[i]=j;
	}
}void qs(string s,string s1){
	s=s+'#'+s1;
	for(int i=1;i<s.size();i++){
		int j=q[i-1];
		while(j&&s[j]!=s[i]){
			j=q[j-1];
		}if(s[i]==s[j]){
			j++;
		}q[i]=j;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>qq;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}while(qq--){
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++)f[i]=0,b[i]=0;
		for(int i=1;i<=s1.size()&&s1[i-1]==s2[i-1];i++)b[i]=1;
		for(int i=s1.size()-1;i>=0&&s1[i]==s2[i];i--){
			f[i]=1;
		}f[s1.size()]=1;
		int ans=0;
		b[0]=1;
		for(int i=1;i<=n;i++){
			ps(s[i][1],s1);
			qs(s[i][2],s2);
			for(int l=s[i][1].size()*2;l<=s[i][1].size()+s1.size();l++){
				int j=l-s[i][1].size()-1;
				if(b[j-s[i][1].size()+1]&&p[l]==s[i][1].size()&&q[l]==s[i][2].size()&&f[j+1]==1){
					ans++;
					break;
				}	
			}
		}
		cout<<ans<<"\n";
	}
}
