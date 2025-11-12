#include<bits/stdc++.h>
using namespace std;

struct node{
	int u,v;
};

int n,q,f,fl,cnt1,cnt2,cnt,ans;
string s[200010][2],t[200010][2];
vector<node> e[2000010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(register int i = 1;i <= n;i++){
		cnt1=cnt2=0;
		cin>>s[i][0]>>s[i][1];
		for(register int j = 0;j < s[i][0].size();j++){
			if((s[i][0][j]!='a'&&s[i][0][j]!='b')||(s[i][1][j]!='a'&&s[i][1][j]!='b')) f=1;
			cnt1+=(s[i][0][j]=='b');
			cnt2+=(s[i][1][j]=='b');
		}if(cnt1!=1||cnt2!=1) f=1;
	} 
	for(register int i = 1;i <= q;i++){
		cnt1=cnt2=0;
		cin>>t[i][0]>>t[i][1];
		if(t[i][0].size()!=t[i][1].size()){
			f=1;
			continue;
		}
		for(register int j = 0;j < t[i][0].size();j++){
			if((t[i][0][j]!='a'&&t[i][0][j]!='b')||(t[i][1][j]!='a'&&t[i][1][j]!='b')) f=1;
			cnt1+=(t[i][0][j]=='b');
			cnt2+=(t[i][1][j]=='b');
		}if(cnt1!=1||cnt2!=1) f=1;
	}if(!f){
		for(register int i = 1;i <= n;i++){
			cnt1=cnt2=0;
			for(register int j = 0;j < s[i][0].size();j++){
				if(s[i][0][j]=='b') cnt1=j;
				if(s[i][1][j]=='b') cnt2=j;
			}cnt=cnt2-cnt1;
//			cout<<cnt<<'\n';
			if(cnt<0) e[100000-cnt].push_back({cnt1,s[i][0].size()-cnt1});
			else e[cnt].push_back({cnt1,s[i][0].size()-cnt1});
		}
		for(register int i = 1;i <= q;i++){
			cnt1=cnt2=ans=0;
			if(t[i][0].size()!=t[i][1].size()){
				cout<<"0\n";
				continue;
			}
			for(register int j = 0;j < t[i][0].size();j++){
				if(t[i][0][j]=='b') cnt1=j;
				if(t[i][1][j]=='b') cnt2=j;
			}cnt=cnt2-cnt1;
//			cout<<cnt<<'\n';
			if(cnt<0){
				for(auto ed:e[100000-cnt]){
					int x=ed.u,y=ed.v;
//					cout<<x<<' '<<cnt1<<' '<<y<<' '<<t[i][0].size()<<'\n';
					if(x<=cnt1&&cnt1+y<=t[i][0].size()) ans++;
				}
			}else{
				for(auto ed:e[cnt]){
					int x=ed.u,y=ed.v;
//					cout<<x<<' '<<cnt1<<' '<<y<<' '<<t[i][0].size()<<'\n';
					if(x<=cnt1&&cnt1+y<=t[i][0].size()) ans++;
				}
			}cout<<ans<<'\n';
		}
		return 0;
	}
	for(register int i = 1;i <= q;i++){
		ans=0;
		if(t[i][0].size()!=t[i][1].size()){
			cout<<"0\n";
			continue;
		}
		for(register int j = 1;j <= n;j++){
			for(register int k = 0;k +s[j][0].size()-1< t[i][0].size();k++){
				string k1=t[i][0].substr(k,s[j][0].size());
				string k2=t[i][1].substr(k,s[j][0].size());
				if(k1==s[j][0]&&k2==s[j][1]){
					string l="",r="";
					l=t[i][0].substr(0,k);
					r=t[i][0].substr(k+s[j][0].size(),t[i][0].size()-k-s[j][0].size());
					if(l+k2+r==t[i][1]){
						ans++;
						break;
					}
				}
			}
		}cout<<ans<<'\n';
	}
	return 0;
}

