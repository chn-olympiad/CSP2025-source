#include<bits/stdc++.h>
using namespace std;
int n,m,rans,s,ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char c[n+1];
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(c[i]=='0'){
			s++;
		}
		else if(c[i]=='1'){
			if(s>=a[i])s++;
			else ans++;
		}
	}
	if(ans>=m){
		rans++;
	}
	if(rans>998)cout<<rans%998;
	else if(rans>353)cout<<rans%353;
	else if(rans>244)cout<<rans%244;
	return 0;
}
