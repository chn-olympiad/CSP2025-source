#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,int> ma;
string s[200010][2],t[2];
int n,m,l,r,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		ma[make_pair(s[i][0],s[i][1])]++;
	}
	while(m--){
		cin>>t[0]>>t[1];
		l=0,r=t[0].size()-1;
		while(t[0][l]==t[1][l]) l++;
		while(t[0][r]==t[1][r]) r--;
		ans=0;
		n=t[0].size()-1;
		for(int i=0;i<=l;i++){
			for(int j=i+1;j<=l;j++){
				ans+=ma[make_pair(t[0].substr(i,j-i+1),t[1].substr(i,j-i+1))];
//				if(ma[make_pair(t[0].substr(i,j-i),t[1].substr(i,j-i))])
//					cout<<t[0].substr(i,j-i)<<" "<<t[1].substr(i,j-i)<<"\n";
			}
			for(int j=r;j<=n;j++){
//				cout<<"i="<<i<<"\tj-i="<<j-i<<endl;
//				if(ma[make_pair(t[0].substr(i,j-i),t[1].substr(i,j-i))])
//					cout<<t[0].substr(i,j-i)<<" "<<t[1].substr(i,j-i)<<"\n";
				ans+=ma[make_pair(t[0].substr(i,j-i+1),t[1].substr(i,j-i+1))];
			}
		}
		for(int i=r;i<=n;i++)
			for(int j=i+1;j<=n;j++)	
				ans+=ma[make_pair(t[0].substr(i,j-i+1),t[1].substr(i,j-i+1))];
//				ans+=ma[make_pair(t[0].substr(i,j-i),t[1].substr(i,j-i))];
		cout<<ans<<"\n";
	}
	return 0;
}
