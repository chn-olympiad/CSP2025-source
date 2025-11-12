#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][3],t1,t2,tt;
bool flag;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1>>t2;ans=0;
		for(int i=1;i<=n;i++){
			int l=s[i][1].size(),dl=t1.size();
			for(int j=0;j<=dl-l;j++){
				tt=t1;flag=1;
					for(int k=j;k<=j+l-1;k++){
						if(tt[k]!=s[i][1][k-j]){
							flag=0;break;
						}
					}
				if(flag){
					for(int k=j;k<=j+l-1;k++){
						tt[k]=s[i][2][k-j];
					}
					if(tt==t2)
					ans++;
				}
				}
			}
		cout<<ans<<"\n"; 
	}
	return 0;
} 
