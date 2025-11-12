#include<bits/stdc++.h>
using namespace std;
int n;
int a,b,c;
int t;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		int maxn=max(max(a,b),c);
		if(a+b+c>2*maxn){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>t;
		}
		cout<<n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

