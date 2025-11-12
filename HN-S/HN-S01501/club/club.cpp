#include<bits/stdc++.h>
using namespace std;
int n[10],ans[10],t,a[100005][5],x[5]; 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n[t];
		for(int i=1;i<=n[t];i++){
			for(int j=1;j<=3;j++){
			cin>>a[i][j];
			}
		}
	}
	while(t--){
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n[t];j++){
				x[i]++;
				if(x[i]>n[t]/2)i++;
				ans[t]+=a[j][i];
			}
		}
	}
	while(t--){
		cout<<ans[t];
	}
	return 0;
}
