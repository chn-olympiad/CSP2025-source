#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int maxn=505;
int a[maxn],t;
int cnt,low=2147483647;
unordered_map<int ,int >ma;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s="";
	bool f=1,f1=1;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c!='1'){
			f=0;	
		}
		else t++;
		s+=c;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma[a[i]]++;
		if(a[i]==0){
			cnt++;
			f1=0;	
		}
		else{
			low=min(low,a[i]);	
		}
	}
	if(t<m){
		cout<<0<<endl;
		return 0;
	}
	if(f){
		if(f1){
			unsigned long long int ans=1;
			for(int i=1;i<=n;i++){
				ans=((ans%mod)*i)%mod;
			}
		cout<<ans<<endl;
		return 0;	
		}else{
			if(cnt+m>n){
				cout<<0<<endl;
				return 0;
			}
		}	
	}
	if(m==1){
		unsigned long long int ans=1;
			for(int i=1;i<=n;i++){
				ans=((ans%mod)*i)%mod;
			}
		cout<<ans<<endl;
		return 0;
	}
}
