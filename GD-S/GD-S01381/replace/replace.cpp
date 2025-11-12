#include<iostream>
#include<cstring>
using namespace std;
int n,q;
string s[200005][3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i =1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string a,b;cin>>a>>b;
		int cnt = 0;
		if(a.size()!=b.size()){
			cout<<"0\n";continue; 
		}
		for(int i =1;i<=n;i++){
			if(s[i][1].size()>a.size())continue;
			if(s[i][1]==a&&s[i][2]==b){
				++cnt;continue;
			}
			for(int j =0;j<a.size();j++){
				if(s[i][1][j]!=a[j])continue;
				string r = a.substr(j,s[i][1].size());
				if(r==s[i][1]){
					string c = b.substr(j,s[i][1].size());
					string qq = a.substr(j+s[i][1].size(),a.size()-(j+s[i][1].size())+1);
					string pp = b.substr(j+s[i][1].size(),a.size()-(j+s[i][1].size())+1);
					string aa = a.substr(0,j),bb = b.substr(0,j);
					if(c==s[i][2]&&((qq==pp||j==a.size()-s[i][1].size())&&(j==0||aa==bb))){
						++cnt;
					}
					if(aa!=bb)break;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
