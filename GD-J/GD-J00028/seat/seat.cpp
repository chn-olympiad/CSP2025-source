#include<bits/stdc++.h>
using namespace std;

const int N=15;
int n,m,a[N][N],tmp,x;
priority_queue<int>q; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>tmp;
	q.push(tmp);
	for(int i=n*m-1;i;--i){
		cin>>x;
		q.push(x);
	}
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			if(q.top()==tmp){
				cout<<j<<' '<<((j%2)?i:n-i+1);
				return 0;
			}
			q.pop();
		}
	}
	return 0;
}
