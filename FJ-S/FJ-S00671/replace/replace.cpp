#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string sa[10086],sb[10086];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sa[i]>>sb[i];
	}
	for(int i=1;i<=m;i++){
		string a,b;
		int ans=0;
		cin>>a>>b;
		for(int j=1;j<=n;j++){
			for(int l=0;l<a.size();l++){
				if(a[l]==sa[j][0]){
					bool flag=1;
					for(int p=0;p<sa[j].size();p++){
						if(sa[j][p]==a[l+p]&&sb[j][p]==b[l+p]){
							continue;
						}
						else{
							flag=0;
							break;
						}
					}
					for(int p=0;p<a.size();p++){
						if(b[p]!=a[p]){
							if(p<l||p>=l+sa[j].size()){
								flag=0;
								break;
							}
						}
					}
					if(flag){
						ans++;
					}
				}
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
