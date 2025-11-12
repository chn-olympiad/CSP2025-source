#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int base=133331;
int n,q;
long long pw[5000010],hs[2][500010];
map<long long,long long>mp;
long long get_hs(long long l,long long r,long long hs[]){
	return hs[r]-hs[l-1]*pw[r-l+1];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		a='$'+a,b='$'+b;
		for(int j=1;j<=a.size()-1;j++){
			hs[0][j]=hs[0][j-1]*base+a[j];
			pw[j]=pw[j-1]*base;
		}
		for(int j=1;j<=a.size()-1;j++){
			hs[1][j]=hs[1][j-1]*base+b[j];
			pw[j]=pw[j-1]*base;
		}
		mp[hs[0][a.size()-1]]=hs[1][a.size()-1];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0\n";
			continue;
		}
		a='$'+a,b='$'+b;
		for(int j=1;j<=a.size()-1;j++){
			hs[0][j]=hs[0][j-1]*base+a[j];
			pw[j]=pw[j-1]*base;
		}
		for(int j=1;j<=a.size()-1;j++){
			hs[1][j]=hs[1][j-1]*base+b[j];
			pw[j]=pw[j-1]*base;
		}
		int l=0,r=0;
		for(int i=1;i<=a.size();i++){
			if(a[i]!=b[i]){
				l=i;
				break;
			}
		}
		for(int i=a.size();i>=1;i--){
			if(a[i]!=b[i]){
				r=i;
				break;
			}
		}
		int ans=0;
		for(int i=l;i>=1;i--){
			for(int j=r;j<=a.size()-1;j++){
				if(mp[get_hs(i,j,hs[0])]==get_hs(i,j,hs[1])){
					ans++;
				}		
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
