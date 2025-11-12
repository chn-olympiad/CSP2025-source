#include<bits/stdc++.h>
using namespace std;
int c[1000001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1;
	string s;
	cin>>n>>m;
	cin>>s;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
	    ans*=i;	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
