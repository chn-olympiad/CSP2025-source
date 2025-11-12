#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1145144],sum=0,tb=0,b[100086],p=0,las=0,ans,lass;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)
			tb++;
	}
	if(m==0&&tb==0){
		cout<<n;
	}
	else{
		if(m==0)	cout<<n-tb;
		else    cout<<tb;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
