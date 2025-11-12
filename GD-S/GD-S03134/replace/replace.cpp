#include <iostream>
#include <vector>
#include <cstring>
#include <string> 
#include <unordered_map>

using namespace std;
const int N=2e5+10;
string S[N][2];
int n,q;
string st1,st2;
unordered_map<string,vector<string>> mp;


void solve(){
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>S[i][0];
		cin>>S[i][1];
		mp[S[i][0]].push_back(S[i][1]);
	}
	while(q--){
		cin>>st1>>st2;
		int ans=0;
		int l=st1.length();
		if (l!=st2.length()){
			ans=0;
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<l;i++){
			for(int j=i;j<l;j++){
				string tmps=st1.substr(i,j-i+1);
				string tmpt=st2.substr(i,j-i+1);
				//cout<<"1"<<endl;

				if (st1.substr(0,i)!=st2.substr(0,i) || st1.substr(j+1,l-j+1)!=st2.substr(j+1,l-j+1)){
					//cout<<"2"<<endl;
					continue;
					
				}
			//	cout<<"2"<<endl;
				if (!mp[tmps].empty()){
					vector<string> tmpv=mp[tmps];
					for(int p=0;p<tmpv.size();p++){
						if (tmpv[p]==tmpt){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		
	}
	
	
	return;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	solve();
	return 0;
} 
