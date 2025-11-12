#include<bits/stdc++.h>
using namespace std;
int a[600];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	char s[600];
	int sum=1;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum*=a[i];
	}
	cout<<sum;
	return 0;
}
