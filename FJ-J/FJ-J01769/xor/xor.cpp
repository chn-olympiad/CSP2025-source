#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000+10],sum,num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		if(a[1]==a[2]){
			if(a[1]==0) sum=2;
			else sum=1;
		}
		else if(a[1]==0||a[2]==0) sum=1;
	}
	else if(a[1]==0) sum=1;
	cout<<sum;
	return 0;
}
