#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int a[105],xiaor,n,m,c=1,r=1;
// c=lie r=hang
bool br;
// 0=++,1=--
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xiaor=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		q.push(a[i]);
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now==xiaor){
			cout<<c<<' '<<r;
			return 0;
		}
		if(c%2==1&&r==n){
			c++;
			br=1;
		}
		else if(c%2==0&&r==1){
			c++;
			br=0;
		}
		else if(br==0){
			r++;
		}
		else{
			r--;
		}
	}
	return 0;
}
