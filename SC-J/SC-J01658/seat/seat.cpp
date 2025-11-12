#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9;
int n,m,num;
int a[N];
priority_queue<int,vector<int>,less<int>> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	while(!q.empty()){
		num++;  
		int x=q.top();
		q.pop();
		if (x==a[1]) break;
		
	}
	num-=1;
	cout<<num/n+1<<" ";
	if ((num/n+1)%2==0){
		cout<<n-(num-(num/n)*n);
	}
	else{
		cout<<num-(num/n)*n+1;
	}
	return 0;
}
