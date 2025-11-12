#include<bits/stdc++.h>
using namespace std;
int n,q;
map<int,map<int,string> > s;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>t1>>t2;
		int l=t1.size(),ans=0;
		for(int i=0;i<l;i++){
			for(int j=i;j<l;j++){
				int f=1;
				for(int a=0;a<i;a++){
					if(t1[a]!=t2[a]){
						f=0;
						break;
					}
				}
				if(!f) continue;
				for(int a=j+1;a<l;a++){
					if(t1[a]!=t2[a]){
						f=0;
						break;
					}
				}
				if(!f) continue;
				for(int a=0;a<n;a++){
					int l1=s[a][0].size(),ff=1;
					if(l1!=j-i+1) continue;
					for(int b=0;b<l1;b++){
						if(s[a][0][b]!=t1[i+b]){
							ff=0;
							break;
						}
					}
					if(!ff) continue;
					for(int b=0;b<l1;b++){
						if(s[a][1][b]!=t2[i+b]){
							ff=0;
							break;
						}
					}
					if(!ff) continue;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
