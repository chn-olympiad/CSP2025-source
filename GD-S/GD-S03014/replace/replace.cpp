#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
string s[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int bgkl=0;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int n=s[i][1].size(),cnt=0,cnt2=0;
		for(int j=0;j<n;j++){
			if(s[i][1][j]!='a'&&s[i][2][j]!='b'){
				bgkl=1;
			}
			if(s[i][2][j]=='b'){
				cnt++;
			}
			if(s[i][2][j]=='b'){
				cnt2++;
			}
		}
		if(cnt!=1||cnt2!=1){
			bgkl=1;
		}
	}
	int flg=0;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int l=t1.size();
		if(t2.size()!=l){
			cout<<0<<"\n";
		}
		if(bgkl==0){
			cout<<1<<"\n";
		}
	}
	return 0;
}
