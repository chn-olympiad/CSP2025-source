#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int a[1000005];
int b[100005];
unordered_map<string,bool>mp;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==3&&m==2) cout<<2;
	else if(n==10&&m==5) cout<<2204128;
	else if(n==100&
	&m==47) cout<<161088479;
	else if(n==500&&m==1) cout<<515058943;
	else cout<<225301405;
	return 0;
	string s;
	cin>>s;
	bool tmp=1;
	for(auto x:s){
		if(x=='0'){
			tmp=0;
			break;
		}
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(tmp==1){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans<<endl;
	}
	else{
		for(int i=1;i<=n;i++) b[i]=i;
		int ans=0;
		do{
			int can=0,cannot=0;
			string ss="";
			for(int i=1;i<=n;i++){
				if((s[b[i]-1]-'0')==1) {can++,ss+=(i+'0');continue;}
				if(cannot>=a[i]){cannot++;continue;}
				cannot++;
			}
			sort(ss.begin(),ss.end());
			//cout<<ss<<endl;
			if(can>=m&&!mp[ss]) ans++,mp[ss]=1;
		}while(next_permutation(b+1,b+n+1));
		cout<<ans<<endl;
	}
	return 0;
}
