#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;

int n,q,ans;
string a1[N],a2[N];
string t1,t2;

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
		if(flag){
			int cnt=0;
			for(int j=0;j<(int)a1[i].size();j++){
				if(a1[i][j]=='b')cnt++;
				if(cnt>1){
					flag=false;
					break;
				}
			}
		}
		if(flag){
			int cnt=0;
			for(int j=0;j<(int)a2[i].size();j++){
				if(a2[i][j]=='b')cnt++;
				if(cnt>1){
					flag=false;
					break;
				}
			}
		}
	}
	while(q--){
		cin>>t1>>t2;
		if(flag){
			int cnt=0;
			for(int i=0;i<(int)t1.size();i++){
				if(t1[i]=='b')cnt++;
				if(cnt>1){
					flag=false;
					break;
				}
			}
		}
		if(flag){
			int cnt=0;
			for(int i=0;i<(int)t2.size();i++){
				if(t2[i]=='b')cnt++;
				if(cnt>1){
					flag=false;
					break;
				}
			}
		}
		if(flag){
			int ans=0;
			int id1,id2;
			for(int i=0;i<(int)t1.size();i++){
				if(t1[i]=='b'){
					id1=i;
					break;
				}
			}
			for(int i=0;i<(int)t2.size();i++){
				if(t2[i]=='b'){
					id2=i;
					break;
				}
			}
			int len=id2-id1;
			for(int i=1;i<=n;i++){
				int l,r;
				for(int j=0;j<(int)a1[i].size();j++){
					if(a1[i][j]=='b')l=i;
				}
				for(int j=0;j<(int)a2[i].size();j++){
					if(a2[i][j]=='b')r=i;
				}
				if(len==(r-l)){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
