#include<bits/stdc++.h>
using namespace std;
int n;
int w[100005];
int wk[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector <int> a[n+5];
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[y].push_back(x);
		a[x].push_back(y);
		cin>>w[i];
	}
	int da;
	cin>>da;
	int dada=0;
	for(int i=1;i<=n;i++){
		cin>>wk[i];
		if(wk[i]!=0){
			dada++;
		} 
	}
	
	if(dada==0&&da==0){
		cout<<0;
		return 0;
	}
	return 0;
}
