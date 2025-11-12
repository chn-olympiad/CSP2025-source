#include<bits/stdc++.h>
using namespace std;
int n,q;
map<pair<string,string>,int>ma;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replece.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(n--){
		string s1,s2;cin>>s1>>s2;
		ma[{s1,s2}]++;
	}
	while(q--){
		string s1,s2;cin>>s1>>s2;
		int l=s1.length(),l2=s2.length();
		if(l!=l2){
			cout<<"0\n";continue;
		}
		int ans=0,t=0,r=l-1;
		while(s1[t]==s2[t])t++;
		while(s1[r]==s2[r])r--;
		string sp="",sq="";
		for(int i=t;i<=r;i++)sp+=s1[i],sq+=s2[i];
		string sx=sp,sy=sq;
		for(int i=r;i<l;i++){
			if(i!=r)sx+=s1[i],sy+=s2[i];
			ans+=ma[{sx,sy}];
			for(int j=t-1;j>=0;j--){
				sx=s1[j]+sx,sy=s2[j]+sy;
				ans+=ma[{sx,sy}];
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


