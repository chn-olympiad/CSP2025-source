#include <bits/stdc++.h>
using namespace std;
int n,q;
string s1[50001],s2[50001],a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.ans","w",stdout);
	cin >>n>>q;
	for(int i=1;i<=n;i++){
		cin >>s1[i]>>s2[i];
	}
	while(q--){
		int ans=0,f=0;
		cin >>a>>b;
		int ll=a.size(),lll=b.size();
		if(ll!=lll){
			cout <<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			int l1=s1[i].size();
			for(int j=0;j<ll;j++){
				if((a[j]==s1[i][0])&&(b[j]==s2[i][0])){
					if(a[j+l1+1]!=b[j+l1+1]){
						break;
					}
					for(int k=j+1;k<j+l1;k++){
					f=1;
						if(a[k]!=s1[i][k-j]||b[k]!=s2[i][k-j]){
							f=0;
							break;
						}
						if(k==j+l1&&a[k]!=b[k]){
							f=0;
							break;
						}
					}
					if(f==1){
						ans++;
						break;
					}
					f=0;
				}
			}
		}
		cout <<ans<<endl;
	}
	return 0;
}
