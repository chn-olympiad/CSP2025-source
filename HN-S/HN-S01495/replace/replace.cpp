#include<iostream>
using namespace std;
string s[212345][2];

int chg(string a,string b,int i){
	int cnt=0;
	string k;
	for(int j=0;j+s[i][0].size()<=a.size();j++){
		bool fg=0;
		k=a;
		for(int l=j;l-j<s[i][0].size();l++){
			if(k[l]!=s[i][0][l-j]){
				fg=1;
				break;
			}
		}
		if(fg) continue;
		for(int l=j;l-j<s[i][1].size();l++){
			k[l]=s[i][1][l-j];
		}
//		cout<<"-"<<k<<endl;
		if(k==b){
			cnt++;
		}
	}
	return cnt;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=chg(a,b,i);
			cout<<i<<' '<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
