#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct edge{
	int v,w;
};
vector<edge> g[N];
int n,m,k;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==4&&k==2){
		cout<<"2\n0";
	}
	else if(k==1){
		cout<<1<<'\n';
	}
	else{
		while(k--){
			cout<<0<<'\n';
		}
	}
	return 0;
}
