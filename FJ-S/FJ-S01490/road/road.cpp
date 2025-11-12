#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,p=0;
	cin>>n>>m>>k;
	for(int q=0;q<m;q++){
		int a,b,c;
		cin>>a>>b>>c;
		p+=c;
	}
	cout<<p;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
