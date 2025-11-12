#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,_T,ans;

string s[1010][2];
string t1,t2,tmp;

bool check(){
	for(int i=0;i<tmp.size();i++){
		if(tmp[i]!=t2[i])return 0;
	}
	return 1;
}

void solve(){
	cin>>t1>>t2;
	for(int i=1;i<=n;i++){
		for(int j=0;j+s[i][0].size()<=t1.size();j++){
			bool flag=1;
			for(int k=0;k<s[i][0].size();k++){
				if(t1[j+k]!=s[i][0][k]){
					flag=0;
					break;
				}
			}
			if(flag){
				tmp=t1;
				for(int k=0;k<s[i][0].size();k++){
					tmp[j+k]=s[i][1][k];
				}
				ans+=check();
			}
		}
	}
	printf("%lld\n",ans);
	ans=0;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%lld%lld",&n,&_T);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(_T--)solve();
	
	return 0;
}
