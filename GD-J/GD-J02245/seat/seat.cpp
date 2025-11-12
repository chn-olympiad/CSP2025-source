#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int v[1005];
bool cmp(int a,int b){
	if(a>b) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>v[i];
	}
	sort(v+1,v+n*m);
	int k=lower_bound(v+1,v+n*m,a)-v;
	k=m*n-k; 
	cout<<k/n+1<<' ';
	if(k/n%2==0) cout<<k%n+1;
	else cout<<n-k%n;
	return 0;
}
