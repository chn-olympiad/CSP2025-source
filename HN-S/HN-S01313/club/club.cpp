#include<bits/stdc++.h>
using namespace std;

int max(int x,int y,int z){
	return max(x,max(y,z));
}

int t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,res,a,b,c;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			res+=max(a,b,c);
		}
		cout<<res<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

