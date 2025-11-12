#include<bits/stdc++.h>

using namespace std;
const int N=2e5+7;
int n,q,ret,ans;
string x,y,s[N][3],tmp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1 ; i <= n ; i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i = 1 ; i <= q ; i++){
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<"\n";
			continue;
		}
		ans=0;
		for(int j = 1 ; j <= n ; j++){
			tmp=x;
			if(tmp.find(s[j][1])!=-1){
				ret=tmp.find(s[j][1]);
				for(int k = ret ; k < ret+s[j][2].size() ; k++){
					tmp[k]=s[j][2][k-ret];
				} 
				if(tmp==y){
					ans++;
				}
			}	
		}
		cout<<ans<<"\n";
	}
	return 0;
}  
