#include <bits/stdc++.h>
using namespace std;
int n,q,l,r,ans,p[200005],pp[200005];
bool flag=1;
string s[200005][3],t1,t2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i = 1;i<=n;i++){
		int t=0,tt=0;
		int len=s[i][1].size();
		for(int j = 0;j<len;j++)
			if((s[i][1][j]!='a'&&s[i][1][j]!='b')||(s[i][2][j]!='a'&&s[i][2][j]!='b'))
				flag=0;
		for(int j = 0;j<len;j++){
			if(s[i][1][j]=='b') t=j;
			if(s[i][2][j]=='b') tt=j;
		}
		p[i]=t-tt,pp[i]=t+1;
	} 
	while(q--){
		cin>>t1>>t2;
		t1=' '+t1,t2=' '+t2;
		int len=t1.size()-1;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		l=ans=0,r=len+1;
		if(flag){
			int t=0,tt=0;
			for(int i = 1;i<=len;i++){
				if(t1[i]=='b') t=i;
				if(t2[i]=='b') tt=i;
			}
			for(int i = 1;i<=n;i++)
				if(pp[i]<=t&&p[i]==t-tt&&s[i][1].size()-pp[i]<=len-t) ans++;
			cout<<ans<<'\n';
			continue;
		}
		while(t1[l+1]==t2[l+1]) l++;
		while(t1[r-1]==t2[r-1]) r--;
		l++,r--;
		for(int i = 1;i<=l;i++){
			for(int j = 1;j<=n;j++){
				if(i+s[j][1].size()-1<r) continue;
				bool flag=1;
				for(int k = i;k<=i+s[j][1].size()-1;k++)
					if(t1[k]!=s[j][1][k-i]||t2[k]!=s[j][2][k-i]){
						flag=0;
						break;
					}
				ans+=flag;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
