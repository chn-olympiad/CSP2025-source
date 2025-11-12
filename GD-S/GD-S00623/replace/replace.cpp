#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N],t[N],a,b;
int n,m,ans;
int main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		int o=0,ff=0,fl=0,fll;
		for(int k=0;k<a.size();k++){
//			if(s[i][o]==a[k]) o++;
//			else o=0;
//			if(o==s[i].size()){
//				for(int l=k;l>=k-s[i].size()+1;l--){
//					
//				}
//			}
			if(a[k]!=b[k]){
				o=k;
				string h=a;
				for(int j=1;j<=n;j++){
					int tt=0;
					for(int l=k;l<s[j].size()+k;l++){
						if(t[j][tt]!=b[l]){
//							cout<<j<<" "<<tt<<" "<<b[l]<<"\n";
							ff=1;
							break;
						}
						tt++;
					}
					if(ff==0){
//						cout<<j<<" 1111111111111";
						for(int l=s[j].size()+k;l<a.size();l++){
							if(a[l]!=b[l]){
								fll=1;
								break;
							} 
						}
						if(fll==0) ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
