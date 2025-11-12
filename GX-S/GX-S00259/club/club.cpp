#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int f[N][5];
int o[N];
int a[N],b[N];
int aa[N],bb[N],cc[N],dd[N];
bool cmp(int a, int b){
	return a>b;
}
void sol(){
	memset(o,0,sizeof(o));
	int n;cin>>n;
	if(n<=4){
		if(n==2){
			for(int i=1;i<=3;i++){
				cin>>a[i];
			}
			for(int i=1;i<=3;i++){
				cin>>b[i];
			}
			int mx=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						mx=max(mx,a[i]+b[j]);
					}
				}
			}
			cout<<mx<<endl;
		}
		else{
			for(int i=1;i<=3;i++){
				cin>>aa[i];
			}
			for(int i=1;i<=3;i++){
				cin>>bb[i];
			}
			for(int i=1;i<=3;i++){
				cin>>cc[i];
			}
			for(int i=1;i<=3;i++){
				cin>>dd[i];
			}
			int mx=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int p=1;p<=3;p++){
							if(i==j&&j==k||i==j&&j==p||i==k&&k==p||j==k&&k==p){
								
							}
							else mx=max(mx,aa[i]+bb[j]+cc[k]+dd[p]);
						}
					}
				}
			}
			cout<<mx<<endl;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>f[i][j];
			}
			o[i]=f[i][1];
		}
		sort(o+1,o+n+1,cmp);
		int ret=0;
		for(int i=1;i<=n/2;i++) ret+=o[i];
		cout<<ret<<endl;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		sol();
	}
	return 0;
}
