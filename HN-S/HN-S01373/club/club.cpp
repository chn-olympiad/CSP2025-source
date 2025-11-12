#include<bits/stdc++.h>
using namespace std;
long long t,w[6],e[100005][4],ans[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t; 
	for(int i=1;i<=t;i++){
		cin>>w[i];
		for(int j=1;j<=w[i];j++){
			cin>>e[j][1]>>e[j][2]>>e[j][3];
			ans[i]+=max(e[j][1],max(e[j][2],e[j][3]));
		}
	} 
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	
	
	
	return 0;
}
