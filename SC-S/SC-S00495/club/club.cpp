#include <bits/stdc++.h>
using namespace std;
int a[100100][4],k[4],ans;
bool cmp(int x,int y){
	return x<y;
}
int maxa[100100],sea[100100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		ans=0;
		bool b=true;
		cin>>n;
		memset(maxa,-1,sizeof(maxa));
		memset(sea,-1,sizeof(sea));
		for(int i=1;i<=n;i++){
			int p;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(maxa[i]<a[i][j]){
					sea[i]=maxa[i];
					maxa[i]=a[i][j];
					p=j;
				}else if(sea[i]<a[i][j]){
					sea[i]=a[i][j];
				}
			}
			k[p]++;
			ans+=maxa[i];
			sea[i]=maxa[i]-sea[i];
		}
		int q;
		for(int i=1;i<=3;i++) if(k[i]>(n/2)) b=false,q=i;
		if(b){cout<<ans<<" ";continue;}
		sort(sea+1,sea+n+1,cmp);
		for(int i=1;i<=k[q]-(n/2);i++) ans-=sea[i];
		cout<<ans<<" ";
	}
	return 0;
}//1 4 0 1 0 0 1 0 0 2 0 0 2 0