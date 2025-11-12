#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,ans,mmy,mmy2,d[200005];
string str[200005][2],s,t;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str[i][0]>>str[i][1];
		for(int j=0;j<str[i][0].size();j++){
			if(str[i][0][j]^str[i][1][j]){
				d[i]=j;
				break;
			}
		}
	}
	while(q--){
		cin>>s>>t;
		if(s.size()^t.size()){
			cout<<"0\n";
			continue;
		}
		mmy=-1;
		for(int i=0;i<s.size();i++){
			if(s[i]^t[i]){
				mmy2=i;
				if(mmy==-1){
					mmy=i;
				}
			}
		}
		ans=n;
		for(int i=1;i<=n;i++){
			if(mmy<d[i]||mmy-d[i]+str[i][0].size()>s.size()+1||mmy-d[i]+str[i][0].size()<=mmy2){
//				cout<<i<<"!!!\n";// 
				ans--;
				continue;
			}
			for(int j=0;j<str[i][0].size();j++){
				if(str[i][0][j]^s[mmy-d[i]+j]||str[i][1][j]^t[mmy-d[i]+j]){
//					cout<<i<<"!!!\n";//
					ans--;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
