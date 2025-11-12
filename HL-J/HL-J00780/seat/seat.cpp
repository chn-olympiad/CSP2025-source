#include<bits/stdc++.h>
#include<queue>
using namespace std;
int a[110][110];
priority_queue<int,vector<int>> pq;
int n,m,k,x=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	int r=k;
	pq.push(k);
	if(n==1&&m==1){
		cout<<k;
		return 0;
	}
	for(int i=1;i<n*m;i++){
		cin>>k;
		pq.push(k);
	}
	if(n%2==0){
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=m;j++){
				a[j][i]=pq.top();
				pq.pop();
			}
			for(int j=m;j>=1;j--){
				a[j][i+i]=pq.top();
				pq.pop();
			}
		}
	}
	else{
		for(int i=1;i<=n+1/2;i++){
			for(int j=1;j<=m;j++){
				a[j][i+1]=pq.top();
				pq.pop();
			}
			for(int j=m;j>=1;j--){
				a[j][i+i]=pq.top();
				pq.pop();
			}
		}
	}
	for(int i=1;i<=n+5;i++){
		for(int j=1;j<=m+5;j++){
			if(a[i][j]==r){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}