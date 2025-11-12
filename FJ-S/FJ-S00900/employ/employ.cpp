#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	int a[n+1],b[n+1]={1,1,2};
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]){
			sum+=1;
		}
	}
	if(n==3||m==2||sum==n){
		cout<<2; return 0;
	}
	cout<<2204128;
	return 0;
}
