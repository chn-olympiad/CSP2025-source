#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,m,maxx=0;
	cin>>n>>m;
	int a[10001];
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
		if(a[i]>maxx){
			a[i]=maxx;
		}	
	}
	if(a[1]==maxx){
		cout<<"1,1";
	}
	else{
		cout<<"1,2";
	}
	return 0;
}
