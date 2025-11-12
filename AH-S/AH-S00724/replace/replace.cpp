#include<bits/stdc++.h>
using namespace std;
int n,q,cntb;
int cha[200010];
string s1[200010],s2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<(int)s1[i].size();j++){
			if(s1[i][j]=='b') {
				cha[i]+=j;
				cntb++;
			}
			if(s2[i][j]=='b') {
				cha[i]-=j;
				cntb++;
			}
		}
		if(cntb!=2) flag=0;
		cntb=0;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(flag){
			int b1=0,b2=0,ans=0;
			for(int i=0;i<(int)t1.size();i++){
				if(t1[i]=='b') b1=i;
				if(t2[i]=='b') b2=i;
			}
			for(int i=1;i<=n;i++){
				if(cha[i]==b1-b2&&(int)s1[i].size()<=(int)t1.size()) ans++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
