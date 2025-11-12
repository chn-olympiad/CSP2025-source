#include<bits/stdc++.h>
using namespace std;
int n,q;
int nxt[200005];
string s[2007];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	if(n*q>=2000009) return 0;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s[n+i];
		s[i]="#"+s[i];
		s[i+n]="#"+s[i+n];
	}
	for(int i=1;i<=q;i++){
		bool flag=0;
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		int sl=s1.size();
		s1="#"+s1;
		s2="#"+s2;
		int poss=0,pose;
		for(int i=1;i<=sl;i++){
			if(s1[i]!=s2[i]){
				if(poss==0) poss=i,pose=i;
				if(poss!=0){
					if(pose=i-1) pose++;
					else{
						flag=1;
						break;
					}
				}
			}
		}
		if(flag){
			cout<<0<<'\n';
			continue;
		}
		for(int j=1;j<=n;j++){
			if(s[j].size()-1<(pose-poss+1))continue;
			for(int st=max((int)(pose-s[j].size()+2),1);st<=poss;st++){
				for(int t1=1;t1<s[j].size();t1++){
					if(s[j][t1]!=s1[st+t1-1]||s[j+n][t1]!=s2[st+t1-1]) break;
					if(t1=s[j].size()-1) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
