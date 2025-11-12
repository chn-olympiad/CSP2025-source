#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans=0;
bool f[505];
deque < int > d;
string s;

void dfs(int x,int flr){
	//cout<<x<<','<<flr<<endl;
	if(flr>=n){
		//cout<<x<<','<<flr<<':'<<d.size()<<endl;
		int failure=0,victory=0;
		deque < int > b;
		b=d;
		for(int i=1;i<=n;i++){
			if(failure<c[b.front()]){
				if(s[i-1]=='1'){
					victory++;
				}else{
					failure++;
				}
			}
			b.pop_front();
		}
		if(victory>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	f[x]=true;
	for(int i=1;i<=n;i++){
		if(f[i]==false){
			d.push_back(i);
			dfs(i,flr+1);
			d.pop_back();
		}
	}
	f[x]=false;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		d.push_back(i);
		dfs(i,1);
		d.pop_back();
	}
	cout<<ans%998244353<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
