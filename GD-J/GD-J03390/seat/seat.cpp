#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
priority_queue<int> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i],q.push(a[i]);
	int i=1,j=1;
	while(!q.empty()){
		if(q.top()==a[1]){
			cout<<i<<" "<<j;
			return 0;
		}
		if(j<m&&i%2==1) j++;
		else if(j>1&&i%2==0) j--;
		else i++;
		q.pop();
	}
	return 0;
}
