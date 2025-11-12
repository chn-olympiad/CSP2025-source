#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int dfs(int d,int sum,int maxx,int suml){
	queue<int>q;
	q.push(a[d]);
	maxx=max(a[d],maxx);
	suml+=a[d];
	if(q.size()>2&&(suml>2*maxx)) return sum%998%244%353;
	while(!q.empty()){
			sum++;
			dfs(d+1,sum,maxx,suml);
			sum--;
			q.pop();
		}	
	return sum%998%244%353;	
	}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dfs(0,0,0,0);
	return 0;
}
