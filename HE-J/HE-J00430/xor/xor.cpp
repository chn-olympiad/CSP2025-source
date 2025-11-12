#include <bits/stdc++.h>
using namespace std;
vector<int> h(5);
vector<vector<int> > l(5);
vector<int> dx;
vector<int> dy;
vector<bool> f(5);
long long n, k;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	l.resize(n+10);
	f.resize(n+10, false);
	h.resize(n+10);
	for(int i=0; i<(n+10); i++){
		l[i].resize(n+10);
	}
	cin>>l[1][1];
	h[1]=l[1][1];
	for(int i=2; i<=n; ++i){
		cin>>l[1][i];
		h[i]=l[1][i];
		l[1][i]=l[1][i]^l[1][i-1];
	}
	for(int i=2; i<=n; ++i){
		for(int j=i; j<=n; ++j){
			if(i==j)l[i][j]=h[i];
			l[i][j]=l[i][j-1]^h[j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; ++j){
			if(l[i][j]==k){
				dx.push_back(i);
				dy.push_back(j);	
			}
		}
	}
	long long size=dx.size(), ans=0;
//						for(long long i=1; i<=n; i++){
//							for(long long j=1; j<i; j++){
//								cout<<'\t';
//							}
//							for(long long j=i; j<=n; j++){
//								cout<<l[i][j]<<'\t';
//							}
//							cout<<endl;
//						}
//						for(long long i=0; i<size; i++){
//							cout<<dx[i]<<'\t'<<dy[i]<<endl;
//						}
						
	for(long long i=0; i<size; i++){
		long long lx=dx[i], ly=dy[i];
		bool flag=false;
		for(long long j=lx; (j<=ly)&&(!flag); j++){
			if(f[j]==true)flag=true;
		}
		if(!flag){
			for(long long j=lx; (j<=ly)&&(!flag); j++){
				f[j]=true;
			}
			ans++;
		}
	}
	cout<<ans;
}
