#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
bool B;
vector<pair<int,int>>f[2000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		if(B==1)continue;
		bool fl=1,fl2=1;
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]>'b')B=1;
			if(s[i][1][j]=='b'){
				if(fl)fl=0;
				else B=1;
			}
			if(s[i][2][j]>'b')B=1;
			if(s[i][2][j]=='b'){
				if(fl2)fl2=0;
				else B=1;
			}
		} 
		if(fl||fl2)B=1;
	}
	if(B){
		int tt=0;
		while(q--){
			tt++;
			string a,b;
			cin>>a>>b;
			int len=a.size(),ans=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<len-(int)s[i][1].size()+1;j++){
					bool fl=0;
					string c=a;
					for(int l=j,r=0;r<s[i][1].size();l++,r++){
						if(a[l]!=s[i][1][r]){
							fl=1;
							break;
						}
						c[l]=s[i][2][r];
					}
					if(!fl&&c==b){
						ans++;
						continue;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	else {
		for(int i=1;i<=n;i++){
			int b1=0,b2=0;
			for(int j=0;j<s[i][1].size();j++){
				if(s[i][1][j]=='b')b1=j;
				if(s[i][2][j]=='b')b2=j;
			} 
			f[b1-b2+1000000].push_back({b1,s[i][1].size()-b1});
		}
		while(q--){
			string a,b;
			cin>>a>>b;
			int len=a.size(),b1=0,b2=0;
			for(int i=0;i<len;i++){
				if(a[i]=='b'){
					b1=i;
				}
				if(b[i]=='b'){
					b2=i;
				}
			}
			int ans=0;
			for(pair<int,int> i:f[b1-b2+1000000]){
				if(i.first<=b1&&i.second<=len-b1)ans++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}


