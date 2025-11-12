#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,z=0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int a[n],c[n];
	string s1;
	bool s[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(s[i]==1)
			z++;
	}
	for(int i=0;i<n;i++)
		cin>>c[i];
	for(int i=0;i<n;i++)
		if(s[i]==1)
			z++;
	cout<<z;
	return 0;
}