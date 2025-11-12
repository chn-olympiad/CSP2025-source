#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int s = 0;
	int m,n,a;
	cin>>m>>n>>a;
	for(int i=1;i<=n;++i){
		int j;
		cin>>j>>j>>j;
		s+=j;
	}
	cout<<s;
	//CCF好坏！！！
	/*
	for(int i=1;i<=INT_MAX;i++)
	cout<<"CCF is Bad!"
	*/ 
	return 0;
}
		