#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
string s1[200010],s2[200010];
bool check(int x,int y){
	string s=s1[0];
	for(int i=y,j=0;i<=y+s1[x].size()-1;i++,j++){
		s[i]=s2[x][j];
		if(s[i]!=s2[0][i]){
			return false;
		}
	}
	if(s==s2[0]){
		return true;
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){ans=0;
		cin>>s1[0]>>s2[0];
		for(int i=1;i<=n;i++){
			if(s1[i].size()>s1[0].size()){
				continue;
			}
			for(int j=0;j<=s1[0].size()-s1[i].size();j++){
				if(s1[0][j]==s1[i][0]){
					if(check(i,j)){
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
