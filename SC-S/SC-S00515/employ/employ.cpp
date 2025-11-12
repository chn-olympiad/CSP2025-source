#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,inf=1e9+5;
int n,m,flag,ans;
string s;
int c[N]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<s.size();i++){
		if(s[i]!='1') flag++;
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	else if(m==n){
		if(flag!=s.size()){
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%998%244%353;;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int tt=0;
		sort(c+1,c+n+1);
		int j=1;
		for(int i=0;i<s.size();i++){
			while(tt>=c[j]){
				tt++;
				j++;
			}
			if(s[i]=='1'){
				tt++;
				j++;
			}
			if(j>n) break;
		}
		if(n-tt+1<m){
			cout<<0;
			return 0; 
		}
		ans=1;
		for(int i=1;i<=n-tt+1;i++){
			ans=ans*i%998%244%353;
		}
		for(int i=1;i<=tt-1;i++){
			ans=ans*i%998%244%353;
		}
//		cout<<tt<<"\n";
		cout<<ans;
	}
	else{
		cout<<0;
	} 
//	else{
//		int tt=0;
//		sort(c+1,c+n+1);
//		int j=1;
//		for(int i=0;i<s.size();i++){
//			int fl=0;
//			while(tt>=c[j]){
//				tt++;
//				j++;
//			}
//			if(s[i]=='1'){
//				tt++;
//				j++;
//				fl++;
//			}
//			if(fl==0) j++;
//		}
//		if(n-tt<m){
//			cout<<0;
//			return 0;
//		}
//		ans=1;
//		for(int i=1;i<=n-tt+1;i++){
//			ans=ans*i%998%244%353;
//		}
//		for(int i=1;i<=tt;i++){
//			ans=ans*i%998%244%353;
//		}
//		cout<<ans;
//	}
	return 0;
} 