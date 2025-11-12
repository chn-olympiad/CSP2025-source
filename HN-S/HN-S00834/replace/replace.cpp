#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int n,q;

string s[N][5];

bool is_z(string a,string b){
	if(a.size()>b.size()) return false;
	if(a.size()==b.size()){
		if(a==b) return true;
		else return false;
	}
	for(int i=0;i<b.size()-a.size();i++){
		string k;
		for(int j=i;j<=i+a.size()-1;j++){
			k+=b[j];
		}
		if(k==a){
//			cout<<i;
			return true;
		}
	}
	return false;
}

string tp(string a,string b,string c){
	string k=b;
	int ip=0;
	for(int i=0;i<b.size()-a.size();i++){
		string m;
		for(int j=i;j<=i+a.size()-1;j++){
			m+=b[j];
		}
		if(m==a){
			ip=i;
		}
	}
//	cout<<ip<<endl;
	for(int i=ip;i<=ip+a.size()-1;i++){
		k[i]=c[i-ip];
	}
	return k;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
//	cout<<tp("abc","deabcd","edf");
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(is_z(s[i][1],a)){
//				cout<<tp(s[i][1],a,s[i][2])<<endl;
				if(tp(s[i][1],a,s[i][2])==b){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
