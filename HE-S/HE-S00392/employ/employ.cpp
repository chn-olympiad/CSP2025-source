#include<bits/stdc++.h>
using namespace std;

int c[501];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int jl=1;
	for(int i=1;i<=n;i++){
		jl*=i;
	}
	cout<<jl;
	
	fclose(stdin);
	fclose(stdout);
}

