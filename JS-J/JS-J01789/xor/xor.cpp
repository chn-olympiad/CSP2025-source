#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,k;
bool p[500005];
void dfs(int v,int m,vector<long long> vt){
	if(v>m){
		for(int i=0;i<m;i++){
			if(i!=0&&vt[i]!=vt[i-1]||vt[i]!=k){
				return;
			}
		}
		cout<<m;
		exit(0);
	}
	int cnt=0;
	for(int i=1;i<=cosl(n/m);i++){
		if(!p[i]){
			if(cnt==0){
				cnt=a[i];
			}
			else{
				cnt=cnt^a[i];
			}
			p[i]=1;
			vt.push_back(cnt);
			dfs(v+1,m,vt);
			vt.pop_back();
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool p1=1,p2=0;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			cnt=a[i];
			continue;
		}
		else if(a[i]!=a[i-1]||a[i]!=k){
			p1=0;
		}
		cnt=cnt^a[i];
		if(a[i]==k){
			p2=1;
		}
	}
	if(cnt==k){
		p2=1;
	}
	if(p1){
		cout<<n;
		return 0;
	}
	for(int i=n-1;i>=2;i--){
		vector<long long> vt;
		dfs(1,i,vt);
	}
	if(p2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
