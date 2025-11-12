#include<bits/stdc++.h>
using namespace std;
namespace xmx{
	const int N=2e5+5;
	int n,q;
	string s1[N],s2[N];
	int A=1,B=1;
	signed main(){
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
			if(B){
				int bf=1,bff=1;
				for(int j=0;j<s1[i].size();j++){
					if(s1[i][j]=='b'){
						if(bf)bf=0;
						else{
							B=0;
							break;
						}
					}
					else if(s1[i][j]!='a'){
						B=0;
						break;
					}
				}
				for(int j=0;j<s2[i].size();j++){
					if(s2[i][j]=='b'){
						if(bff)bff=0;
						else{
							B=0;
							break;
						}
					}
					else if(s2[i][j]!='a'){
						B=0;
						break;
					}
				}
			}
		}
		if(B){
			int qm[N],hm[N];
			int qm_[N],hm_[N];
			for(int i=1;i<=n;i++){
				int fg=0;
				for(int j=0;j<s1[i].size();j++){
					if(s1[i][j]=='b'){
						fg=1;
						continue;
					}
					if(fg==0){
						qm[i]++;
					}
					else{
						hm[i]++;
					}	
				}
				fg=0;
				for(int j=0;j<s2[i].size();j++){
					if(s2[i][j]=='b'){
						fg=1;
						continue;
					}
					if(fg==0){
						qm_[i]++;
					}
					else{
						hm_[i]++;
					}	
				}
			}
			int qm1_,hm1_,qm2_,hm2_;
			string s1_,s2_;
			for(int i=1;i<=q;i++){
				int ans=0;
				cin>>s1_>>s2_;
				int fg=0;
				for(int j=0;j<s1_.size();j++){
					if(s1_[j]=='b'){
						fg=1;
						continue;
					}
					if(fg==0){
						qm1_++;
					}
					else{
						hm1_++;
					}	
				}
				fg=0;
				for(int j=0;j<s2_.size();j++){
					if(s2_[j]=='b'){
						fg=1;
						continue;
					}
					if(fg==0){
						qm2_++;
					}
					else{
						hm2_++;
					}	
				}
				for(int j=1;j<=n;j++){
					if(qm1_-qm[j]==qm2_-qm_[j] && qm1_>=qm[j] && qm2_>=qm_[j] && hm1_>=hm[j] &&hm2_>=hm_[j]){
						ans++;
					}
				}
				cout<<ans<<"\n";
			}
		}
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	return xmx::main();
}
