#include <bits/stdc++.h>
using namespace std;
int i,a,n,g=0,p[1000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>p[i];
		if((p[i]+p[i+1]+p[i+2]+p[i+3])>(2*p[i+3])){
			g=g+1;
		}else if((p[i]+p[i+1]+p[i+2])>(2*p[i+2])){
			g=g+1;
		}
		if((p[i]+p[i+1]+p[i+3])>(2*p[i+3])){
			g=g+1;
		}	
	}
	cout<<g-1;
	return 0;
}
