#include <bits/stdc++.h>
using namespace std;



int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int n,m,a,b,c,t;
	cin>>n;
	for (int i=0;i<n;i++){
		t=0;
		cin>>m;
		for (int j=0;j<m;j++){
			cin>>a>>b>>c;
			t+=max(a,max(b,c));
		}
		cout<<t<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
