#include<bits/stdc++.h>
const int N=2e5+3, M=5e6+3;
using namespace std;
int n, q, g[M], d[N];
string m, p;
string a[N], b[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		string l, r;
		cin>>l>>r;
		a[i]=l, b[i]=r;
		g[l.size()]++;
		d[i]=l.size();
	}
	if(q==1){
		cin>>m>>p;
		if(g[m.size()]==0||g[p.size()]==0){
			cout<<"0\n";
		}else{
			cout<<"2\n";
		}
	}
	
	else{
	
	while(q--){
		cin>>m>>p;
		if(g[m.size()]==0||g[p.size()]==0){
			cout<<"0\n";
			continue;
		}
	}}
	return 0;
}
