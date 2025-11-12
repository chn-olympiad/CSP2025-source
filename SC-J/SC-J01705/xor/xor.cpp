#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],x[N],c,sum;
deque<int> g[N];
priority_queue<pair<int,int> > q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=a[i]^x[i-1];
		g[x[i]].push_back(i);}
	for(int i=0;i<n;i++){
		if(i) g[x[i]].pop_front();
		c=x[i]^k;
		int l=-1;
		for(auto it:g[c]){
			l=it;
			break;}
		if(l==-1) continue;
		else q.push({-l,i+1});}
	c=0;
	while(!q.empty()){
		int l=-q.top().first,r=q.top().second;
		q.pop();
		if(r>c) c=l,sum++;}
	cout<<sum;
	return 0;
} 