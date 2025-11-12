#include<bits/stdc++.h>
using namespace std;
int a[105],b[105][105],r;
queue<int> q;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		q.push(a[i]);
	}
	int k=1;
	while(!q.empty()&&k<=m){
		if(k%2==1){
			for(int i=1;i<=n;i++){
				b[k][i]=q.front();
				q.pop();
			}
			k++;	
		}
		if(k%2==0){
			for(int i=n;i>=1;i--){
				b[k][i]=q.front();
				q.pop();
			}
			k++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==r){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
}
