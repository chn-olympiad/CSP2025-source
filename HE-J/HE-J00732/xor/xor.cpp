#include<bits/stdc++.h>
using namespace std;
int n,m,b,tot;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)  tot++;
	}
	if(m==0&&n==tot){
		cout<<0;
	}
	else if(m==1){
		cout<<tot;
	}
	else  cout<<n-tot;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
