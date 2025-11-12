#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
long long ans=0;
vector<int> p;
vector< vector<int> > path;
void DFS(int start,int l){
	if(p.size()==l){
		path.push_back(p);
	}
	for(int i=start;i<n;i++){
		p.push_back(a[i]);
		DFS(i+1,l);
		p.pop_back();
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		a.push_back(s);
	}
	for(int i=3;i<=n;i++){
		DFS(0,i);
	}
	for(int i=0;i<path.size();i++){
		int cnt=0;
		int imax=0;
		for(int j=0;j<path[i].size();j++){
			cnt+=path[i][j];
			imax=max(imax,path[i][j]);
		}
		if(cnt>2*imax){
			ans++;
		}
	}
	cout<<ans%998244353<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
