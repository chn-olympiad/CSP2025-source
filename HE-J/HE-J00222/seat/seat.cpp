#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	int n,m;
	int a[105],b[105];
	int c=0,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]<a[i+1]){
			b[i]=a[i+1];
			
		}
	}
	r=a[1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
