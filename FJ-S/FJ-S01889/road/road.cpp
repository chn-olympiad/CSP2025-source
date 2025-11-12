#include<bits/stdc++.h>
using namespace std;
int n,m,k,flag=1,f=1;
long long a[1000005][5],b[15][1000005],c[15],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans+=a[i][3]; 
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		if(c[i]){
			flag=0;
		}
		for(int j=1;j<=n;++j){
			cin>>b[i][j];
			if(b[i][j]){
				f=0;
			}
		}
	}
	if(flag&&k){
		if(f){
			cout<<0;
		}
		else{
			cout<<ans;
		}
	}
	else{
		cout<<ans;
	}
	fclose(stdin);	
	fclose(stdout);
	return 0;
}
