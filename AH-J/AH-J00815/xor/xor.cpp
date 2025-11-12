#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int yhh[500010];
int he;
struct ans{
	int s,e;
};
vector<ans> an;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		yhh[i]=yhh[i-1]^a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int v=(yhh[j]&yhh[i-1]);
			//cout<<v<<" ";
			if(v==m){
				an.push_back({i,j});
			}
		}
	}
	cout<<an.size();
	return 0;
}
