#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	int t,n;
	int MAX=0;
	int ans=0;
	cin>>t;
	if(n/2==0){
		cin>>n;
	}
	for(int i=1;i<=t;i++){
		for(int d=1;d<=n;d++){
			for(int j=1;j<=3;j++){
				if(MAX <= j){
					MAX==j;
				}
				ans+=MAX;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
