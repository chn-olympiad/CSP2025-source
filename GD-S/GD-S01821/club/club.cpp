#include <bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
int lovex[100010],lovey[100010],lovez[100010];
int love[100010][4];
int cont[4];
void solve(){
	for(int i=1;i<=n;i++){
		if((lovex[i]==max(max(lovex[i],lovey[i]),max(lovey[i],lovez[i])))&&(cont[1]<(n/2))){
			++cont[1];
			ans+=lovex[i];
		}else  if((lovey[i]==max(max(lovex[i],lovey[i]),max(lovey[i],lovez[i])))&&(cont[2]<(n/2))){
					ans+=lovey[i];
					++cont[2];
				}
				else{
					ans+=lovez[i];
					++cont[3];
				}	
		}
		cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int y=1;y<=n;y++){
			for(int j=1;j<=3;j++){
			cin>>love[y][j];
				if(j==1){
					lovex[y]=love[y][j];
				}
				if(j==2){
					lovey[y]=love[y][j];
				}
				if(j==3){
					lovez[y]=love[y][j];
				}
			}
		}
		sort(lovex+1,lovex+n);
		sort(lovey+1,lovey+n);
		sort(lovez+1,lovez+n);
		solve();
		ans=0;
	}
	return 0;
} 
