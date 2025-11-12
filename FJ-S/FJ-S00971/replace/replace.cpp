#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

int n,miku;
string s[200005][2];
map<string,string> mp;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("replace.in","r",stdin); freopen("replace.out","w",stdout);
	cin>>n>>miku; int q=miku;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		mp[s[i][1]]=s[i][2];
	} 
	while(miku--){
		string t1,t2; cin>>t1>>t2;
		int l1=t1.length(),l2=t2.length();
		if(l1!=l2){
			cout<<0<<endl;
			continue;
		}
		if(n<=100){
			int ans=0;
			for(int i=0;i<l1;i++){
				for(int j=i;j<l1;j++){
					string tmp1=t1.substr(i,j-i+1);
					if(mp.count(tmp1)){
						string x=t1.substr(0,i),z=t1.substr(j+1);
						if(x+mp[tmp1]+z==t2) ans++;
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		
	}
	return 0;
}

