#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int nx[n];
	for(int i=0;i<n;i++){
		cin>>nx[i];
	}
	sort(nx,nx+n);
	int sum=0;
	for(int i=0;i<a.size();i++){
		if(a[i]=='1')sum++;
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	int sum1=0;
	for(int i=0;i<n;i++){
		if(nx[i]==nx[i+1])sum1+=2;
	}
	cout<<sum1;
	return 0; 
}
