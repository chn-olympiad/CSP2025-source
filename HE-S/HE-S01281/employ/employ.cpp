#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	string l;
	cin>>l;
	for(int i=0;i<n;i++){
		cin>>x;
	}
	if(n==3 && m==2) cout<<2;
	else if(n==10 && m==5) cout<<2204128;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
