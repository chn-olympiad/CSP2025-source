#include<bits/stdc++.h>
#define sjh0626s return
#define code 0
#define ll long long
#define PII pair<int,int>
using namespace std;
int T=1,n,q,ans,pos[200010][2];
string s[200010][2],t[200010][2];
bool TaskB;
void solve(){
	cin>>n>>q;
//	TaskB=1;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	if(n<=100){
		for(int i=1;i<=q;i++){
			ans=0;
			cin>>t[i][0]>>t[i][1];
			if(t[i][0].size()!=t[i][1].size()){
				cout<<"0\n";
				continue;
			}
			for(int j=0;j<(int)t[i][0].size();j++){
				for(int k=1;k<=n;k++){
					if(j+s[k][0].size()-1>=t[i][0].size())continue;
					string a=t[i][0].substr(j,s[k][0].size());
					if(a==s[k][0]){
						string ta=t[i][0];
						t[i][0].replace(j,s[k][0].size(),s[k][1]);
						if(t[i][0]==t[i][1])ans++;
						t[i][0]=ta;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<(int)s[i][0].size();j++){
				if(s[i][0][j]=='b')pos[i][0]=j;
			}
			for(int j=0;j<(int)s[i][1].size();j++){
				if(s[i][1][j]=='b')pos[i][1]=j;
			}
		}
		for(int i=1;i<=q;i++){
			ans=0;
			cin>>t[i][0]>>t[i][1];
			if(t[i][0].size()!=t[i][1].size()){
				cout<<"0\n";
				continue;
			}
			int posa=0,posb=0;
			for(int j=0;j<(int)t[i][0].size();j++){
				if(t[i][0][j]=='b')posa=j;
			}
			for(int j=0;j<(int)t[i][1].size();j++){
				if(t[i][1][j]=='b')posb=j;
			}
			for(int j=1;j<=n;j++){
				if(posa>=pos[j][0]&&t[i][0].size()+pos[j][0]>s[j][0].size()+posa){ //可替换
					if(posa-pos[j][0]+pos[j][1]==posb+1)ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//cin>>T;
	while(T--)solve();
	sjh0626s code;
}