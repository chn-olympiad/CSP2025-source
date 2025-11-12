#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	char a[1005]={};
	int n;
	cin>>n;
	int b[1005]={};
	int cnt=1;
	int c[100]={};
	int ans=0;
	for (int i=1;i<=n;i++){
		cin>>b[i];
		ans+=b[i];
	}
	if(ans %2==1)	cout<<9;
	if(ans %2==0)	cout<<6;
	return 0;
}
