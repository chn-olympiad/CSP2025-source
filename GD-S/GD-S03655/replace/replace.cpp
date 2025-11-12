#include<bits/stdc++.h>
using namespace std;
string sx[200010],sy[200010];
string tx[200010],ty[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,k,ans=0;cin>>n>>k;
	for(int i=1; i<=n; i++) 
		cin>>sx[i]>>sy[i];
	for(int i=1; i<=k; i++)
		cin>>tx[i]>>ty[i];
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			string cur=tx[i];
			int pos=cur.find(sx[j]);
			int flag=1;
			if(pos!=-1){
				for(int l=pos; l<sy[j].size()+pos; l++){
					cur[l]=sy[j][l-pos];
				}
				if(cur.size()!=ty[i].size()) flag=0;
				for(int l=0; l<ty[i].size(); l++){
					if(cur[l]!=ty[i][l]) flag=0;
				}
				if(flag) ans++;
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
