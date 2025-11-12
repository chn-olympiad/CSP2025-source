#include<bits/stdc++.h>
using namespace std;
int n,m,ns[505],ans;
bool tg[505];
bool yf[505];
//vector<int>v;
void dfs(int dep,int qz,int cs){
	//cout<<"dep:"<<dep<<" qz:"<<qz<<" cs:"<<cs<<endl;
	if(cs==m){
//		for(int i=0;i<v.size();i++){
//			cout<<v[i]<<' ';
//		}
//		cout<<endl;
		ans++;
		ans%=998244353;
	}
	for(int i=0;i<n;i++){
		if(!yf[i]&&ns[i]>qz){
			int rc=qz;
			int rc2=cs;
			if(!tg[dep]){
				rc+=1;
			}else{
				rc2+=1;
			}
			yf[i]=true;
			//v.push_back(i);
			dfs(dep+1,rc,rc2);
			//v.pop_back();
			yf[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		char rc;
		cin>>rc;
		if(rc=='1'){
			tg[i]=true;
		}
	}
	for(int i=0;i<n;i++){
		cin>>ns[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
