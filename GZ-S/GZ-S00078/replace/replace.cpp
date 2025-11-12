//GZ-S00078 贵阳市南明区李端棻中学 向一坤
#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+7; 
int n,q;
string s[mx][3];
int next[mx];
//int gz(){
//	for(int i=1;i<=n;i++){
//		if(n)
//		while(next[i])
//	}
//}
bool pd(string s1,string s2){
	if(s1.size()<s2.size()) return 0;
	for(int i=0;i<s2.size();i++){
		if(s1[i]!=s2[i]) return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	string t1,t2;
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<t1.size();j++){
				//cout<<t1.substr(j,s[i][1].size())<<' '<<s[i][1]<<'\n';
				if(pd(t1.substr(j,s[i][1].size()),s[i][1])){
					string t3=t1.substr(0,j)+s[i][2]+t1.substr(j+s[i][1].size(),t2.size());
					//cout<<" "<<t3<<' '<<t2<<'\n';
					if(t3==t2) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}
